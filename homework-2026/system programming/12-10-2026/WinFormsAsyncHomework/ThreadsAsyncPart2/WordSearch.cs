using System;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace ThreadsAsyncPart2;

internal static class WordSearch
{
    // Ищем именно слово, а не часть другого слова. Регистр не важен.
    public static async Task<long> CountInFileAsync(string path, string word, CancellationToken token)
    {
        var pattern = $@"(?<![\p{{L}}\p{{N}}_]){Regex.Escape(word)}(?![\p{{L}}\p{{N}}_])";
        var regex = new Regex(pattern, RegexOptions.IgnoreCase | RegexOptions.CultureInvariant);
        long count = 0;

        using var reader = new StreamReader(path);
        while (true)
        {
            token.ThrowIfCancellationRequested();
            string? line = await reader.ReadLineAsync(token);
            if (line is null)
                break;
            count += regex.Matches(line).Count;
        }
        return count;
    }
}
