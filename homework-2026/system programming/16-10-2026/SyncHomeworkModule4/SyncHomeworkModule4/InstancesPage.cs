using System.Drawing;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal sealed class InstancesPage : UserControl
{
    public InstancesPage(int instanceNumber)
    {
        var description = new Label
        {
            Dock = DockStyle.Fill,
            Font = new Font("Segoe UI", 13),
            TextAlign = ContentAlignment.MiddleCenter,
            Text = $"Это экземпляр №{instanceNumber} из 3 возможных.\n\n" +
                   "Откройте приложение ещё два раза.\n" +
                   "При запуске четвёртой копии появится сообщение, и она закроется.\n\n" +
                   "Для ограничения используются три именованных Mutex."
        };
        Controls.Add(description);
    }
}
