using System;

namespace _5lesson
{
    class Program
    {
        static void ArrayTest() {
            int[] vector = new int[int.Parse(Console.ReadLine())];
            vector[0] = 1;

            for(int i = 0; i < vector.Length; i++) {
                vector[i] = i;
            }

            int[] vector1 = new int[] {0, 1, 2, 3};
            int[] vector2 = {1, 2, 3};

            int[,] arr = new int[3, 2];
            int[,] arr2 = {{1,2}, {3,2}, {4,2}};
            int[,,] arr3 = new int[3, 2, 3];
        }

        static void Exers1() {
            int num;

            do {
                Console.WriteLine("Enter int: ");
            
            } while (!int.TryParse(Console.ReadLine(), out num) || num <= 0);

            int len = (int)Math.Log10(num) + 1;
            char[] arr = new char[len];
            int rem, i = len - 1;

            do {
                rem = num % 10;
                num/=10;
                arr[i] = (char)(rem + 0);
                i--;
            } while (num != 0);

            for(int j = 0; j < len; j++) {
                Console.Write($"item: {arr[j]}");
            }
        }

        static void Exers2() {
            int[] arr = new int[5];

            for(int i = 0; i < arr.Length; i++) {
                arr[i] = i;
            }

            foreach(int el in arr) {
                Console.WriteLine($"el: {el} \t");
            }

            int[] arr1 = (int [])arr.Clone();
            arr1[3] = 2342;

            Array.Sort(arr1);
            Array.Reverse(arr1);
            
            foreach(int el in arr1) {
                Console.WriteLine($"el1: {el} \t");
            }
        }

        // homepage
        static void SortBubble() {
            Console.WriteLine("Enter array size: ");
            int size = Console.Read();
            int[] arr = new int[size];

            Console.WriteLine($"Enter members of array, int[] size: {size}");
            for (int i = 0; i < size; i++) {
                arr[i] = Console.Read();
            }
            for(int i = 0; i < size; i++) {
                Console.WriteLine($"element: {arr[i]}");
            }
        }

        static void Main(string[] args)
        {
            SortBubble();
        }
    }
}
