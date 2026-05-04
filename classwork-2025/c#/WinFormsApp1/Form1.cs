namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public int a, b;
        double result;
        public Form1()
        {
            InitializeComponent();
        }
        private void button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void batton_plus_Click(object sender, EventArgs e)
        {
            a = Convert.ToInt32(textBox_first_number.Text);
            b = Convert.ToInt32(textBox_second_number.Text);
            result = a + b;
            MessageBox.Show("Output: " + result, "Answer", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button_minus_Click(object sender, EventArgs e)
        {
            a = Convert.ToInt32(textBox_first_number.Text);
            b = Convert.ToInt32(textBox_second_number.Text);
            result = a - b;
            MessageBox.Show("Output: " + result, "Answer", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button_div_Click(object sender, EventArgs e)
        {
            a = Convert.ToInt32(textBox_first_number.Text);
            b = Convert.ToInt32(textBox_second_number.Text);
            result = a / b;
            MessageBox.Show("Output: " + result, "Answer", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button_multipl_Click(object sender, EventArgs e)
        {
            a = Convert.ToInt32(textBox_first_number.Text);
            b = Convert.ToInt32(textBox_second_number.Text);
            result = a * b;
            MessageBox.Show("Output: " + result, "Answer", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button_clear_Click(object sender, EventArgs e)
        {
            textBox_first_number.Clear();
            textBox_second_number.Clear();

        }
    }
}
