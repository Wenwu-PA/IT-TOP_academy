namespace index
{
    internal class Program
    {
        public class Student
        {
            public int Id;
            public string Surname;
            public string FirstName;
            public string Patronomic;
            public string Group;
            public int Age;
            public Grade[] Grades_of_student;
            public Student() { }//конструктор по умолч
            
            public Student(
                int idp,
                string Surnamep,
                string FirstNamep,
                string Patronomicp,
                string Groupp,
                int Agep,
                params Grade[] grades)
            {
                Id = idp;
                Surname = Surnamep;
                FirstName = FirstNamep;
                Patronomic = Patronomicp;
                Group = Groupp;
                Age = Agep;
                Grades_of_student = grades;

                
            }
        }
        public class Grade
        {
            public string Itemname;
            public int[] Points;
            public Grade(string i_name, params int[] number) { 
                Itemname = i_name;
                Points = number;
            }
        }

        public class test
        {
            public Student[] test_stud;
            public test() {
                test_stud = new Student[] {
                new Student(1,"aboba","boba","dolba","rpaiasd",18,new Grade("Hyna angl",5,4,2,2),new Grade("mob_psyho100",2,34,4,2)),
                new Student(2,"adeoba","boba","dolba","rpaiasd",12,new Grade("Hyna angl",5,4,2,2),new Grade("mob_psyho100",2,34,4,2)),
                new Student(3,"abwefrweoba","bofgba","dolba","rpaiasd",112,new Grade("Hyna angl",5,4,2,2),new Grade("mob_psyho100",2,34,4,2)),
                };
            }
        }
        static void Main(string[] args)
        {
        
        }
    }
}
