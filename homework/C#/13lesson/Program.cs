using System;

//exceptions
namespace _13lesson
{
    class Program
    {
        public delegate int Row(int num);

        class Example {
            public static int Series(int num) {
                int len = (int)Math.Log10(num) + 1;
                return len;
            }

            public static void Display(int i) {
                Console.Write($"i: {i}");
            }
        }
        static void Main(string[] args)
        {

            Console.WriteLine($"Hello World! {Example.Series(6)}");
            Example.Display(8);
            Row delRow = new Row(Example.Series);
            Console.WriteLine($"222: {delRow(10)}");

        }
    }
}
