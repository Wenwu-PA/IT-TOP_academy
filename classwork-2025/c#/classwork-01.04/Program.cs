namespace CV
    {
    internal class Program
    {
        public interface ISposob
        {
            void SendMessage(string message);

        }
        public class SMS : ISposob 
        { 
            public void SendMessage(string message)
            {
                Console.WriteLine($"Send by mail {message}");
            }

        }
        public class Mail : ISposob
        {
            public void SendMessage(string Mail)
            {
                Console.WriteLine($"Send by mail {Mail}");
            }

        }
        public class VK

        static void Main(string[] args)
        {
            ISposob s1 = new Mail();
            ISposob s2 = new SMS();
            s1.SendMessage("Hello");
            s2.SendMessage("Hello");

            ISposob[] s = { s1, s2 };
            foreach(ISposob sposob in s)
            {
                if (sposob is SMS)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                }
                if (sposob is Mail)
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                }
                sposob.SendMessage("Hello");
            }
            Console.ResetColor();

            object s3 = new SMS();
            ISposob s4 = s3 as SMS;
            if (s4 != null)
            {
                s4.SendMessage("Hello");
            }
            else {
                Console.WriteLine("Nope");
            }
            object s5 = new VK();
            ISposob s6  = s5 as SMS;
            if (s6 != null)
            {
                s6.SendMessage("Eccept");

            }
            else Console.WriteLine("Nope");
        }
    }
}