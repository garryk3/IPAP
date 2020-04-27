using System;

namespace _10lesson
{
    class Program
    {
        static void Main(string[] args)
        {
            
          ExtendedClass test = new ExtendedClass(22);

          Console.WriteLine($"value: {test.testVal2}");
        }
    }

    class StaticClass {
        static int[] arr  = { 1, 2, 3 };

        static StaticClass() {}
    }
 
    class SimpleClass {
          private int field1 = 1;
          private int field2 = 2;

          public SimpleClass(int arg1, int arg2) {
              field1 = arg1;
              field2 = arg2;
          }

          public SimpleClass(int arg):this(arg, 0) {}

          public SimpleClass(SimpleClass test):this(test.field1, test.field2) {}
    }

    class WithInnerClass {
        private int outerField = 1;

        int GetVal() {
                return outerField;
            }

        class InnerClass {
            private int innerField = 1;

            int GetInnerVal() {
                return innerField;
            }
        }
    }

    class ExtendedClass:WithInnerClass {
        static int testVal = 10;
        public int testVal2;

        public ExtendedClass(int arg) {
            testVal2 = arg;
            ExtendedClass.testVal = arg;
        }
    }
}
