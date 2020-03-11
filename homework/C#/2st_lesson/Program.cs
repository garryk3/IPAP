using System;

namespace _2st_lesson
{
    class Program
    {
        static void Types() {
                        // types
            // 1 byte
            byte byteVar = 255; // 0...255
            sbyte sbyteVar = 0; // -128...127
            // 2 byte
            char charVar = 'a'; // U+0000 U+ffff
            short shortVar = -10; // -32xxx ... 32xxx
            ushort ushortVar = 10; // 0 .... 64xxx
            // 4 byte
            int intVar = -34343; // -2 xxx xxx xxx ... 2 xxx xxx xxx
            uint uintVar = 324234; // 0 ... 4 xxxx xxxx xxxx
            // 8 byte
            long longVar = 8098098045646598; // -9 xxx xxx xxx xxx xxx xxxx ....9 xxx xxx xxx xxx xxx xxxx xxx
            ulong ulongVar = 809809809809809; // 0 ... 18 xxxx xxxx xxxx xxxx xxxx xxx

            // floating x = s * m * 10 в степени n
            double doubleVar = -10.17080980;
            float floatVar = (float)-10.17080980;        

            // 16 byte
            decimal decimalVar = (decimal)10.17080980;

            int sizeDecimal = sizeof(decimalVar);

            // boolean
            bool boolVar = false;

            // string
            string stringVar = "asdlfj";

            // object
            object objectVar = new object();
        } 
        static void Main(string[] args)
        {
        }
    }
}
