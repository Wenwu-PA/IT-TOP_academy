namespace WinFormsApp1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            textBox_first_number = new TextBox();
            batton_plus = new Button();
            textBox_second_number = new TextBox();
            button_minus = new Button();
            button_div = new Button();
            button_multipl = new Button();
            button_exit = new Button();
            label_first_number = new Label();
            label_second_number = new Label();
            button_clear = new Button();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // textBox_first_number
            // 
            textBox_first_number.Location = new Point(485, 416);
            textBox_first_number.Name = "textBox_first_number";
            textBox_first_number.Size = new Size(100, 23);
            textBox_first_number.TabIndex = 0;
            // 
            // batton_plus
            // 
            batton_plus.Location = new Point(12, 12);
            batton_plus.Name = "batton_plus";
            batton_plus.Size = new Size(75, 23);
            batton_plus.TabIndex = 1;
            batton_plus.Text = "PLUS";
            batton_plus.UseVisualStyleBackColor = true;
            batton_plus.Click += batton_plus_Click;
            // 
            // textBox_second_number
            // 
            textBox_second_number.Location = new Point(688, 416);
            textBox_second_number.Name = "textBox_second_number";
            textBox_second_number.Size = new Size(100, 23);
            textBox_second_number.TabIndex = 2;
            // 
            // button_minus
            // 
            button_minus.Location = new Point(93, 12);
            button_minus.Name = "button_minus";
            button_minus.Size = new Size(75, 23);
            button_minus.TabIndex = 3;
            button_minus.Text = "MINUS";
            button_minus.UseVisualStyleBackColor = true;
            button_minus.Click += button_minus_Click;
            // 
            // button_div
            // 
            button_div.Location = new Point(174, 12);
            button_div.Name = "button_div";
            button_div.Size = new Size(75, 23);
            button_div.TabIndex = 4;
            button_div.Text = "DIV";
            button_div.UseVisualStyleBackColor = true;
            button_div.Click += button_div_Click;
            // 
            // button_multipl
            // 
            button_multipl.Location = new Point(255, 12);
            button_multipl.Name = "button_multipl";
            button_multipl.Size = new Size(75, 23);
            button_multipl.TabIndex = 5;
            button_multipl.Text = "MULTIPLY";
            button_multipl.UseVisualStyleBackColor = true;
            button_multipl.Click += button_multipl_Click;
            // 
            // button_exit
            // 
            button_exit.Location = new Point(12, 415);
            button_exit.Name = "button_exit";
            button_exit.Size = new Size(75, 23);
            button_exit.TabIndex = 6;
            button_exit.Text = "EXIT";
            button_exit.UseVisualStyleBackColor = true;
            button_exit.Click += button5_Click;
            // 
            // label_first_number
            // 
            label_first_number.AutoSize = true;
            label_first_number.Location = new Point(485, 398);
            label_first_number.Name = "label_first_number";
            label_first_number.Size = new Size(74, 15);
            label_first_number.TabIndex = 7;
            label_first_number.Text = "First number";
            // 
            // label_second_number
            // 
            label_second_number.AutoSize = true;
            label_second_number.Location = new Point(688, 398);
            label_second_number.Name = "label_second_number";
            label_second_number.Size = new Size(91, 15);
            label_second_number.TabIndex = 8;
            label_second_number.Text = "Second number";
            // 
            // button_clear
            // 
            button_clear.Location = new Point(117, 415);
            button_clear.Name = "button_clear";
            button_clear.Size = new Size(75, 23);
            button_clear.TabIndex = 9;
            button_clear.Text = "CLEAR";
            button_clear.UseVisualStyleBackColor = true;
            button_clear.Click += button_clear_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.Image = (Image)resources.GetObject("pictureBox1.Image");
            pictureBox1.Location = new Point(12, 41);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(776, 283);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.TabIndex = 10;
            pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ButtonFace;
            ClientSize = new Size(800, 450);
            Controls.Add(pictureBox1);
            Controls.Add(button_clear);
            Controls.Add(label_second_number);
            Controls.Add(label_first_number);
            Controls.Add(button_exit);
            Controls.Add(button_multipl);
            Controls.Add(button_div);
            Controls.Add(button_minus);
            Controls.Add(textBox_second_number);
            Controls.Add(batton_plus);
            Controls.Add(textBox_first_number);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBox_first_number;
        private Button batton_plus;
        private TextBox textBox_second_number;
        private Button button_minus;
        private Button button_div;
        private Button button_multipl;
        private Button button_exit;
        private Label label_first_number;
        private Label label_second_number;
        private Button button_clear;
        private PictureBox pictureBox1;
    }
}
