using System.Diagnostics;

namespace calculate
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            proc.StartInfo = new System.Diagnostics.ProcessStartInfo("calc.exe");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            proc.Start();
        }

        private void process1_Exited(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Process[] procArr = Process.GetProcessesByName("CalculatorApp");
            if (procArr.Length > 0)
            {
                procArr[0].Kill();
            }
            else {
                MessageBox.Show("Error");
            }
        }
    }
}
