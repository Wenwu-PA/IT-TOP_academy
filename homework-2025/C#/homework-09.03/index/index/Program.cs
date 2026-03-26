using System.Security.Cryptography.X509Certificates;

namespace index
{
    internal class Program
    {
        public class My_class
        {
            public int Num;
            public string Name;
            public bool isStudent;
            public My_class() { }

            public My_class(int num)
            {
                Num = num;
                Name = "test";
                isStudent = true;
            }
            public My_class(int num, string Name)
            {
                Num = num;
                Name = "test";
                isStudent = true;
            }
            public My_class(int num, string Name, bool isStudent)
            {
                Num = num;
                Name = "test";
                isStudent = true;
            }

            public void Print()
            {
                Console.WriteLine($"number = {Num}, name = {Name}, isStudent = {isStudent}");

            }
        }
        static void Main(string[] args)
        {
            My_class my_Class = new My_class(134,"asda",true);
            my_Class.Print();
        }
    }
}