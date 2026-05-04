namespace WinFormsApp2
{
    public partial class Form1 : Form
    {
        private string loginP = "admin";
        private string passwordP = "admin";
        public Form1()
        {
            InitializeComponent();
            //размер формы по умолчанию
            Size = new Size(900, 190);
            //начальное положение
            StartPosition = FormStartPosition.CenterScreen;
            //вызываем метод для настройки автозаполнения
            SetupAutoComplete();
            //// Вызываем метод и скрываем поля для ввода данных
            ToggleElementVisibility(false);
            //// вызываем метод для заполнения combobox
            //SetupEventTypeComboBox();
            //radioButton_on_line.Checked = true;
        }
        private void ToggleElementVisibility(bool visible)
        {
            //устанавливаем видимость для названия проекта
            label3.Visible = visible;
            textBox3.Visible = visible;
            //видимость для элементов назначения даты
            label4.Visible = visible;
            maskedTextBox1.Visible = visible;
            //элементы для выбора типа события
            label5.Visible = visible;
            comboBox1.Visible = visible;
            //кнопки выбора формата мероприятия
            radioButton1.Visible = visible;
            radioButton2.Visible = visible;
            //элементы сообщения
            label6.Visible = visible;
            textBox1.Visible = visible;
            //
            listBox1.Visible = visible;

        }
        private void button_enter_parol_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == loginP && textBox2.Text == passwordP)
            {
                // MessageBox.Show("Успешно");
                Size = new Size(900, 700);
                //сделаем логин и пароль недоступными
                textBox1.ReadOnly = true;
                textBox2.Enabled = false;
                //показываем элементы для ввода данных
                ToggleElementVisibility(true);

            }
            else
            {
                MessageBox.Show("Неверный логин или пароль");
            }
        }
        //метод для настройки автозаполнения
        private void SetupAutoComplete()
        {
            //1. создадим новую коллекцию строк, которая будет использоваться для автозаполнения
            var autoCompleteCollection = new AutoCompleteStringCollection();
            //2. добавляем массив строк в эту колллекцию
            autoCompleteCollection.AddRange(new string[]
            {
        "Космос", "Альфа", "Контент", "Англия", "Архипелаг", "Коралл", "Криптовалюта", "Корабль"
            });
            //3. присваиваем созданную коллекцию для свойтсва текстбокса
            textBox3.AutoCompleteCustomSource = autoCompleteCollection;
            //4. Связываем текстовое поле с набором предложений для автозаполнения
            textBox3.AutoCompleteMode = AutoCompleteMode.Suggest;
            //5. указываем, что текстовое поле будет использовать нашу коллекцию для автозаполнения
            textBox3.AutoCompleteSource = AutoCompleteSource.CustomSource;
        }
        //метод для создания списка доступных типов события
        private void SetupEventTypeComboBox()
        {
            comboBox1.Items.AddRange(new string[]
            {
        "Семинар", "Праздник", "Выставка", "Открытый урок"
            });
            //устанавливаем элемент по умолчанию - первый элемент списка
            comboBox1.SelectedIndex = 0;
        }

        private void linkLabel1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://google.com");
        }



        private void button_save_Click(object sender, EventArgs e)
        {
            if (!checkBox1.Checked)
            {
                MessageBox.Show("подтвердите, что вы ознакомились с условиями организации");
                return;
            }
            //собираем данные из полей
            string name = textBox3.Text;
            string date = maskedTextBox1.Text;
            string eventType = comboBox1.SelectedItem.ToString();
            string format = radioButton1.Checked ? "on_line" : "off_line";
            string message = textBox4.Text;
            //добавляем строку
            listBox1.Items.Add($"{name} - {date} - {eventType} - {format}- {message}");
            //очистим поля
            textBox3.Clear();
            maskedTextBox1.Clear();
            comboBox1.SelectedIndex = 0;
            radioButton1.Checked = true;
            textBox4.Clear();
            checkBox1.Checked = false;
        }
    }
}
