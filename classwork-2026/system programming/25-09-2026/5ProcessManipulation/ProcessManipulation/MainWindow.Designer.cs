namespace ProcessManipulation
{
    partial class MainWindow
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
            groupBox1 = new GroupBox();
            AvailableAssemblies = new ListBox();
            groupBox2 = new GroupBox();
            StartedAssemblies = new ListBox();
            Start = new Button();
            Stop = new Button();
            CloseWindow = new Button();
            Refresh = new Button();
            RunNotepad = new Button();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(AvailableAssemblies);
            groupBox1.Location = new Point(475, 42);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(280, 373);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Доступные сборки";
            // 
            // AvailableAssemblies
            // 
            AvailableAssemblies.FormattingEnabled = true;
            AvailableAssemblies.ItemHeight = 15;
            AvailableAssemblies.Location = new Point(12, 22);
            AvailableAssemblies.Name = "AvailableAssemblies";
            AvailableAssemblies.Size = new Size(258, 334);
            AvailableAssemblies.TabIndex = 0;
            AvailableAssemblies.SelectedIndexChanged += AvailableAssemblies_SelectedIndexChanged;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(StartedAssemblies);
            groupBox2.Location = new Point(48, 42);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(280, 373);
            groupBox2.TabIndex = 1;
            groupBox2.TabStop = false;
            groupBox2.Text = "Запущенные процессы";
            // 
            // StartedAssemblies
            // 
            StartedAssemblies.FormattingEnabled = true;
            StartedAssemblies.ItemHeight = 15;
            StartedAssemblies.Location = new Point(11, 22);
            StartedAssemblies.Name = "StartedAssemblies";
            StartedAssemblies.Size = new Size(259, 334);
            StartedAssemblies.TabIndex = 0;
            StartedAssemblies.SelectedIndexChanged += StartedAssemblies_SelectedIndexChanged;
            // 
            // Start
            // 
            Start.Enabled = false;
            Start.Location = new Point(363, 96);
            Start.Name = "Start";
            Start.Size = new Size(75, 23);
            Start.TabIndex = 2;
            Start.Text = "Старт";
            Start.UseVisualStyleBackColor = true;
            Start.Click += Start_Click;
            // 
            // Stop
            // 
            Stop.Enabled = false;
            Stop.Location = new Point(364, 132);
            Stop.Name = "Stop";
            Stop.Size = new Size(75, 23);
            Stop.TabIndex = 3;
            Stop.Text = "Стоп";
            Stop.UseVisualStyleBackColor = true;
            Stop.Click += Stop_Click;
            // 
            // CloseWindow
            // 
            CloseWindow.Enabled = false;
            CloseWindow.Location = new Point(354, 169);
            CloseWindow.Name = "CloseWindow";
            CloseWindow.Size = new Size(93, 23);
            CloseWindow.TabIndex = 4;
            CloseWindow.Text = "Закрыть окно";
            CloseWindow.UseVisualStyleBackColor = true;
            CloseWindow.Click += CloseWindow_Click;
            // 
            // Refresh
            // 
            Refresh.Enabled = false;
            Refresh.Location = new Point(363, 205);
            Refresh.Name = "Refresh";
            Refresh.Size = new Size(75, 23);
            Refresh.TabIndex = 5;
            Refresh.Text = "Обновить";
            Refresh.UseVisualStyleBackColor = true;
            Refresh.Click += Refresh_Click;
            // 
            // RunNotepad
            // 
            RunNotepad.Location = new Point(355, 242);
            RunNotepad.Name = "RunNotepad";
            RunNotepad.Size = new Size(92, 41);
            RunNotepad.TabIndex = 6;
            RunNotepad.Text = "Запуск\r\nблокнота";
            RunNotepad.UseVisualStyleBackColor = true;
            RunNotepad.Click += RunNotepad_Click;
            // 
            // MainWindow
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(RunNotepad);
            Controls.Add(Refresh);
            Controls.Add(CloseWindow);
            Controls.Add(Stop);
            Controls.Add(Start);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "MainWindow";
            Text = "Управление дочерними процессами";
            FormClosing += MainWindow_FormClosing;
            groupBox1.ResumeLayout(false);
            groupBox2.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private GroupBox groupBox2;
        private ListBox AvailableAssemblies;
        private ListBox StartedAssemblies;
        private Button Start;
        private Button Stop;
        private Button CloseWindow;
        private Button Refresh;
        private Button RunNotepad;
    }
}
