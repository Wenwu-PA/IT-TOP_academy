namespace ThreadNumbers;

// Запускает вычисление в отдельном потоке и позволяет управлять им.
internal sealed class NumberWorker
{
    private readonly CancellationTokenSource _cancellation = new();
    private readonly ManualResetEventSlim _pause = new(true);
    private readonly Thread _thread;

    public NumberWorker(
        Action<CancellationToken, ManualResetEventSlim> work,
        Action onCompleted,
        Action<Exception> onError)
    {
        _thread = new Thread(() =>
        {
            try
            {
                work(_cancellation.Token, _pause);

                if (!_cancellation.IsCancellationRequested)
                    onCompleted();
            }
            catch (OperationCanceledException) when (_cancellation.IsCancellationRequested)
            {
                // Остановка по кнопке — нормальная ситуация.
            }
            catch (Exception ex)
            {
                onError(ex);
            }
        })
        {
            IsBackground = true
        };
    }

    public void Start() => _thread.Start();

    public void Pause() => _pause.Reset();

    public void Resume() => _pause.Set();

    public void Stop()
    {
        _cancellation.Cancel();
        _pause.Set(); // Разбудить поток, если он был на паузе.
        _thread.Join(); // Дождаться полного завершения потока.
        _pause.Dispose();
        _cancellation.Dispose();
    }
}
