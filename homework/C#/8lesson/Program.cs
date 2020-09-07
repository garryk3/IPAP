using System;
using System.Collections.Generic;

namespace _8lesson
{
    // Generics
    class Program
    {
        static void Test1() {
            List<int> list = new List<int>();
            list.Add(10);
            list.Add(20);
            int a = list[1];
            list[1] = 100;
            list.RemoveAt(1);
            list.Insert(1, a);
            for(int i = 0; i < list.Count; i++) {
                list[i] = i;
            }
            foreach(int i in list) {
                Console.WriteLine($"i: {list[i]} ");
            }
        }
        static void Main(string[] args)
        {
            SortString();
        }

        static void SortString() {
            List<string> list = new List<string>();
            list.Add("Moscow");
            list.Add("Tver");
            list.Add("Astrahan");
            list.Sort();
            foreach (string city in list) {
                Console.WriteLine(city);
            }

        }
    }

}
