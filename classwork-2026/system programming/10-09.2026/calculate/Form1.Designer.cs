namespace calculate
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
            start = new Button();
            button3 = new Button();
            proc = new System.Diagnostics.Process();
            SuspendLayout();
            // 
            // start
            // 
            start.Font = new Font("Segoe UI", 19F);
            start.Location = new Point(55, 81);
            start.Name = "start";
            start.Size = new Size(301, 46);
            start.TabIndex = 1;
            start.Text = "старт";
            start.UseVisualStyleBackColor = true;
            start.Click += button2_Click;
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 19F);
            button3.Location = new Point(55, 187);
            button3.Name = "button3";
            button3.Size = new Size(301, 46);
            button3.TabIndex = 1;
            button3.Text = "стоп";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // proc
            // 
            proc.StartInfo.Domain = "";
            proc.StartInfo.LoadUserProfile = false;
            proc.StartInfo.Password = null;
            proc.StartInfo.StandardErrorEncoding = null;
            proc.StartInfo.StandardInputEncoding = null;
            proc.StartInfo.StandardOutputEncoding = null;
            proc.StartInfo.UseCredentialsForNetworkingOnly = false;
            proc.StartInfo.UserName = "";
            proc.SynchronizingObject = this;
            proc.Exited += process1_Exited;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(411, 327);
            Controls.Add(button3);
            Controls.Add(start);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
        }

        #endregion

        private Button start;
        private Button button3;
        private System.Diagnostics.Process proc;
    }
}
