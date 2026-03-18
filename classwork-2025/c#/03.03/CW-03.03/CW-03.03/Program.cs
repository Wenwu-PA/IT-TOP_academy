using System.Data.SqlTypes;
using System.Security.Cryptography.X509Certificates;

namespace figures
{
    internal class Program
    {
        public class Tomato : Paslenov { 
            public string Rod { get; set; }
            public string Sort { get;set }
            public Tomato(string sort) : base()
            {
                Rod = "tomato";
                Sort = sort;
            }
            public override void Print()
            {
                base Print(){
                    Console.WriteLine($"Rod {Rod}\n" +
                                      $"Sort {Sort}");
                }
            }
        }
        static void main()
        {
            Tomato Tom = new Tomato("Zloy");
            Console.WriteLine(Tom);
        }

    }
}