using System.Numerics;

namespace first
{
    internal class Program
    {
        public class Pupil
        {
            public int age;
            public string name;
            public int id;

            public Pupil(int age, string name)
            {
                this.age = age;
                this.name = name;
            }
        }
        public class  Processor
        {
            public int mark;
            public string vendor;

            public Processor(int mark, string vendor)
            {
                this.mark = mark;
                this.vendor = vendor;
            }
            public void print()
            {
                Console.WriteLine(mark);
                Console.WriteLine(vendor);
            }
        }
        static void Main(string[] args)
        {
            int[] myArray;
            myArray = new int[10] { 1, 3, 3, 4, 5, 6, 7, 8, 9, 0 };
            foreach (int i in myArray)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();

            Console.WriteLine("max " + myArray.Max());
            Console.WriteLine("sum " + myArray.Sum());
            Console.WriteLine("min " + myArray.Min());
            Console.WriteLine("sred_arif " + myArray.Average());
            Console.WriteLine("has element 5 " + myArray.Contains(5));

            string[] mystring;
            mystring = new string[10];
            string str1 = "hello";
            string str2 = str1;
            str2 += "i";

            string Path = "C:../Student/f.txt";
            Console.WriteLine(Path);


;           string str6 = "abcd";
            string str7 = "abcd";
            Console.WriteLine(str6 = str7);
            Console.WriteLine(str6.CompareTo(str6));
            Console.WriteLine(str7.CompareTo(str7));
            string str8 = "les";
            Console.WriteLine(str1.StartsWith(str8));
            Console.WriteLine(str8.EndsWith(str8));
            Console.WriteLine(str8.LastIndexOf("s"));

            int n1, n2;
            Console.WriteLine("Input ");
            n1= int.Parse(Console.ReadLine());
            Console.WriteLine("Input ");
            n2 = int.Parse(Console.ReadLine());
            for (int i = 0; i < n2; i++)
            {
                if (i % 2==0) Console.Write(i+ " ");
            }
            Console.WriteLine();



        }
    }
}
