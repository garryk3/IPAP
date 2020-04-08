using System;
using System.Text;

namespace _7lesson
{
    class Program
    {
        static void Ex1() {
            StringBuilder st = new StringBuilder();
            st.Append("Hello World!");
            char ch = st[1];
            Console.WriteLine(ch);
            st[1] = 'O';
            Console.WriteLine(st);
        }
        static void Main(string[] args)
        {
            Ex1();
        }
    }
}
