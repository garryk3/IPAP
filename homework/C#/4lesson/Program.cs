using System;
using static System.Math;

namespace _4lesson
{
    class Program
    {
        static void Greeteng() {
            Console.WriteLine("Enter current hour: ");
            int now = Convert.ToInt32(Console.ReadLine());
            while(now > 24) {
                Console.WriteLine("Time is incorrect");
                now = Convert.ToInt32(Console.ReadLine());
            }
            string greeting = "Good night";
            if(now >= 6 && now < 12) {
                greeting = "Good morning";
            } else if(now >= 12 && now < 18) {
                greeting = "Good day";
            } else if(now >= 18 && now < 21) {
                greeting = "Good evening";
            }
            Console.WriteLine(greeting);
        }

        static string CalculateEngine(int a, int b) {
            Console.Write("Enter operator: ");
            string operatorFor = Console.ReadLine();

            int? result = null;
            switch (operatorFor) {
                case "+": {
                    result = a + b;
                    Console.WriteLine($"a + b = {result}");
                    break;
                }
                case "-": {
                    result = a - b;
                    Console.WriteLine($"a - b = {result}");
                    break;
                }
                case "*": {
                    result = a * b;
                    Console.WriteLine($"a * b = {result}");
                    break;
                }
                case "/": {
                    result = a / b;
                    Console.WriteLine($"a / b = {result}");
                    break;
                }
                default: {
                    Console.WriteLine($"Incorrect operator {operatorFor}");
                    break;
                }
            }
            return result != null ? result.ToString() : "stop";
        }

        static void Calculate() {
            Console.Write("Enter a: ");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter b: ");
            int b = Convert.ToInt32(Console.ReadLine());
            int result = 0;
            bool isContinue = true;

            do {
                string stringResult = CalculateEngine(a, b);
                if(stringResult == "stop") {
                    Console.WriteLine("Operation failed");
                    isContinue = false;
                    break;
                }
                result = Convert.ToInt32(stringResult);
                a = result;
                Console.Write("Enter next value: ");
                b = Convert.ToInt32(Console.ReadLine());
            } while(isContinue);
            Console.WriteLine($"result = {result}");
        }

        static void CalculateResult() {
            Console.Write("enter a: ");
            double a = double.Parse(Console.ReadLine());
            Console.Write("enter b: ");
            double b = double.Parse(Console.ReadLine());
            Console.Write("enter c: ");
            double c = double.Parse(Console.ReadLine());

            double d = Pow(b, 2) - 4 * a * c;
            if(d < 0) {
                d = -d;
            }
            double x1 = -b + Sqrt(d) / (2 * a);
            double x2 = -b - Sqrt(d) / (2 * a);

            Console.WriteLine($"result: {x1}, {x2}");
        }

        static void SampleLists() {
            const int size = 10000000;
            int[] vectorIn = new int[size];
            int[] vector1 = new int[size];
            int[] vector2 = new int[size];

            Random random = new Random();

            for(int i = 0; i < size; i++) {
                vectorIn[i] = random.Next();
            }
            DateTime now = DateTime.Now;

            for(int i = 0; i < size; i++) {
                vector1[i] = vectorIn[i] / 2;
            }
            TimeSpan ts = DateTime.Now - now;
            now = DateTime.Now;
            Console.WriteLine($"time 1: {ts.TotalMilliseconds}");
            for(int i = 0; i < size; i++) {
                vector2[i] = vectorIn[i] >> 1;
            }
            TimeSpan ts1 = DateTime.Now - now;
            Console.WriteLine($"time 2: {ts1.TotalMilliseconds}");
        }

        static void SampleOperatorOverloads() {
            Complex c1 = new Complex(4, 5);
            Complex c2 = new Complex(1, 5);
            Complex c3 = c1 + c2;
            Console.WriteLine($"res: {c3}");
        }

        struct Complex {
            public double Re;
            public double Im;

            public Complex(double real, double imaginary) {
                Re = real;
                Im = imaginary;
            }

            public static Complex operator +(Complex c1, Complex c2) {
                return new Complex(c1.Re + c2.Re, c1.Im + c2.Im);
            }

            public override string ToString() {
                return string.Format($"{Re} + i{Im}");
            }
        }

        static void Main(string[] args)
        {
            SampleOperatorOverloads();
        }
    }
}