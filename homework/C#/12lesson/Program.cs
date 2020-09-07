using System;

namespace _12lesson
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Planets list;
            string s = Console.ReadLine();
            list = (Planets)Enum.Parse(typeof(Planets), s);

            foreach(string name in Enum.GetNames(typeof(Planets))) {
                Console.WriteLine(name);
            }
            Console.WriteLine(list.ToString());
            Console.WriteLine();
            Console.WriteLine(Enum.GetName(typeof(Planets), 1));
        }
    }

    enum Planets: uint {
        Mars,
        Earth,
        Venera = 99
    }

    struct Points {
        private double x;
        private double y;

        public Points(double xi, double yi) {
            x = xi;
            y = yi;
        }
    }
}
