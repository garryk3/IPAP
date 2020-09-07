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

        static void Ex2() {
            int x = 10;
            int y = 10;
            Test(ref x); // value by link
            Test(out y); // return link in output
        }

        static void Test(ref int y) {
            y++;
        }
        static void Test2(out int y) {
            y = 100;
        }

        static void Main(string[] args)
        {
            Ex2();
        }
    }
}
