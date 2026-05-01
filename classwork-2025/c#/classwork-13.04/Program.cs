namespace My_delegate_l
{
    public enum Operation { Add,Minux,Multiply
    public delegate T Operation <T,K>(T a, K k);

    public static int Add(int a, int k) => a + k;
    public static string AddText(string a, string b) => a + b;
    public static string ConcText(string t, int i) => t + i;

    

}