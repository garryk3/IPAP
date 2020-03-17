using System;

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

        static void Calculate() {
            Console.Write("Enter a: ");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter b: ");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter operator: ");
            string operatorFor = Console.ReadLine();

            int result;
            switch (operatorFor) {
                case "+": {
                    result = a + b;
                    Console.WriteLine($"a + b = {result}");
                    break;
                }
                case "-": {
                    result = a + b;
                    Console.WriteLine($"a - b = {result}");
                    break;
                }
                case "*": {
                    result = a + b;
                    Console.WriteLine($"a * b = {result}");
                    break;
                }
                case "/": {
                    result = a + b;
                    Console.WriteLine($"a / b = {result}");
                    break;
                }
                default: {
                    Console.WriteLine($"Incorrect operator {operatorFor}");
                    break;
                }
            }
        }

        static void Main(string[] args)
        {
            Calculate();
        }
    }
}
