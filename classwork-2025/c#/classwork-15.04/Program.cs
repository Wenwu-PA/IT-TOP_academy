namespace Delegate_account
{
    public delegate void AccountHandler(string message);

    internal class Program
    {
        public class Account
        {
            public int sum;
            public AccountHandler taken;

            public Account(int sumP) {
                sum = sumP;
            }

            public void RegistrHandler(AccountHandler handler) { 
                taken = handler;
            }
            public void Add(int sum) => this.sum++;
            public void Take(int sum)
            {
                if (this.sum >= sum)
                {
                    this.sum--;
                    taken?.Invoke($"Accept: {this.sum}");
                }
                else
                {
                    Console.WriteLine("Warning!: litle money in your pay");
                }
            }
        }
        public static void PrintSimpleMessage(string message) {
            Console.WriteLine(message);
        }
        static void Main(string[] args) {

            Account acc = new Account(200);
        
        }
    }
}