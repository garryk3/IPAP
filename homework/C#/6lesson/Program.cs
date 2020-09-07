using System;
using System.IO;
using System.Text;

namespace _6lesson
{
    class Program
    {
        static void ExString() {
            char a = 'a';
            int A = (int)'A';
            char charA = (char)A;
        }

        static void ExStringEncode() {
            string s = "t стр";

            File.WriteAllText("default.txt", s);
            File.WriteAllText("utf8.txt", s, Encoding.UTF8);
            File.WriteAllText("ascii.txt", s, Encoding.ASCII);

            Encoding utf8 = Encoding.UTF8;
            Encoding ascii = Encoding.ASCII;

            PrintBytes(utf8.GetBytes(s));
            PrintBytes(ascii.GetBytes(s));
        }

        static void PrintBytes(byte[] bytes) {
            for (int i = 0; i < bytes.Length; i++) {
                Console.WriteLine($"{i}: {bytes[i]}, ");
            }
        }
        static void Main(string[] args)
        {
            ExStringEncode();
        }
    }
}
