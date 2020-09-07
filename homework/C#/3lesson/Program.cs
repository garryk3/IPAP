using System;

namespace _3lesson
{
    class Program
    {

        static void Sample() {
            byte x = 7; // 0000 01111
            byte y = 2; // 0000 0010

            Console.WriteLine($"~{x} = {~x}");
            Console.WriteLine($"{x}|{y} = {x|y}");
            Console.WriteLine($"{x}&{y} = {x&y}");
            Console.WriteLine($"{x}^{y} = {x^y}");
            Console.WriteLine($"{x}<<{1} = {x<<1}");
            Console.WriteLine($"{x}<<{3} = {x<<3}");
        }

        static void SampleStructures() {
            PointClass class1 = new PointClass();
            class1.x = 10;
            class1.y = -10;

            PointClass class2 = class1;
            class2.x = 4;

            PointStruct struct1 = new PointStruct();
            struct1.x = 10;
            struct1.y = -10;

            PointStruct struct2 = struct1;
            struct2.x = 4;

            Console.WriteLine($"Class 1 x: {class1.x} y: {class1.y}");
            Console.WriteLine($"Class 2 x: {class2.x} y: {class2.y}");
            Console.WriteLine($"Struct 1 x: {struct1.x} y: {struct1.y}");
            Console.WriteLine($"Struct 2 x: {struct2.x} y: {struct2.y}");
            Console.WriteLine($"Struct 2 x: {struct2.x} y: {struct2.y}");
        }
        
        static void Main(string[] args)
        {
            Sample();
        }
    }

    class PointClass {
        public int x;
        public int y;
    }

    struct PointStruct {
        public int x;
        public int y;
    }
}
