using System.Collections;

namespace My_enum
{
    internal class Program {
        public class Student<T>
        {
            public T id { get; set; }
            public string name { get; set; }
            public Student()
            {

            }
            public Student(T idP, string nameP)
            {
                id = idP;
                name = nameP;
            }
            public override string ToString()
            {
                return $"Id = {id}\t{name}";
            }
            public class Group() : IEnumerator
            {
                public string GroupName { get; set; }
                public Student<int>[] students { get; set; }

                public object Current => throw new NotImplementedException();

                public Group(string gnP)
                {
                    GroupName = gnP;
                    new Student<int>[](1, "Volodya"),
                new Student<int>[](2, "Boris"),

            }

                public object Current
                {
                    get { if (position || position >= students.Length)
                            throw new InvalidOperationException();
                        return Student[position]
                        }
                }

                public bool MoveNext()
                {
                    throw new NotImplementedException();
                }

                public void Reset()
                {
                    throw new NotImplementedException();
                }
            }
        }
        static void Main(string[] args)
        {
            Group g1 = new Group("PRO");
            while (g1.MoveNext())
            {
                Console.WriteLine(g1.Current);
            }
        }
    }
}