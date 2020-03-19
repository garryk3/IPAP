using System;

namespace _2st_lesson
{
    class Program
    {
        // static void Types() {
        //                 // types
        //     // 1 byte
        //     byte byteVar = 255; // 0...255
        //     sbyte sbyteVar = 0; // -128...127
        //     // 2 byte
        //     char charVar = 'a'; // U+0000 U+ffff
        //     short shortVar = -10; // -32xxx ... 32xxx
        //     ushort ushortVar = 10; // 0 .... 64xxx
        //     // 4 byte
        //     int intVar = -34343; // -2 xxx xxx xxx ... 2 xxx xxx xxx
        //     uint uintVar = 324234; // 0 ... 4 xxxx xxxx xxxx
        //     // 8 byte
        //     long longVar = 8098098045646598; // -9 xxx xxx xxx xxx xxx xxxx ....9 xxx xxx xxx xxx xxx xxxx xxx
        //     ulong ulongVar = 809809809809809; // 0 ... 18 xxxx xxxx xxxx xxxx xxxx xxx

        //     // floating x = s * m * 10 в степени n
        //     double doubleVar = -10.17080980;
        //     float floatVar = (float)-10.17080980;        

        //     // 16 byte
        //     decimal decimalVar = (decimal)10.17080980;

        //     int sizeDecimal = sizeof(decimalVar);

        //     // boolean
        //     bool boolVar = false;

        //     // string
        //     string stringVar = "asdlfj";

        //     // object
        //     object objectVar = new object();

        //     // Int16, Int32, Int64, Double, Single, Object ...
        // }

        static void TypeTo() {
            // преобразование типов (явное, неявное)
            object s = "sadfasd";
            // int i = (int)24.7; // 24
            string s2 = 3434.ToString();
        }

        static void Concatenate() {
            Console.WriteLine("Enter something: ");
            string s = Console.ReadLine();
            Console.WriteLine($"You enter {s}, length: {s.Length}");
            Console.WriteLine(s.Length);
        }

        static void Calculate() {
            // x + y = z;
            Console.WriteLine("Enter x: ");
            int x = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter y: ");
            int y = int.Parse(Console.ReadLine());
            Console.WriteLine($"You enter x: {x}, y: {y}, z = x + y = {x + y}");
        } 

        static void Test() {
            Console.WriteLine("Push enter after leaving room...");
            Console.ReadKey();
            DateTime before = DateTime.Now;

            Console.WriteLine("Push enter after return");
            Console.ReadKey();
            DateTime after = DateTime.Now;

            TimeSpan ts = after - before;
            Console.WriteLine($"Time: {ts.Hours} hours {ts.Minutes} min {ts.Seconds} seconds");
            Console.WriteLine((int)ts.TotalSeconds);
        }

        static void HowManyDaysToSummer() {
            DateTime now = DateTime.Now;
            DateTime firstSummerDay = new DateTime(2020, 06, 01);
            TimeSpan timeToSummer = firstSummerDay - now;
            Console.WriteLine($"Days to next summer is: {timeToSummer.Days}");
        }

        static void Main(string[] args)
        {
            HowManyDaysToSummer();
        }
    }
}
