using System;

namespace _11lesson
{
    class Program
    {
        static void Main(string[] args)
        {
            ExtendAbstractClass test = new ExtendAbstractClass();
            ITest yy = new Test();
            Console.WriteLine($"Hello World!, {test.GetPi()}");
        }
    }

    class WithVirtulaClass {
        public int testVal = 10;

        public virtual int GetDoubleTestVal() {
            return testVal * 2;
        }
    }

    class ExtendedClass:WithVirtulaClass {
        public override int GetDoubleTestVal() {
            return testVal * testVal * 3;
        }
        public ExtendedClass(int arg2) {

        }
    }

    abstract class AbstractClass {
        public abstract double GetPi();
    }

    class ExtendAbstractClass:AbstractClass {
        public override double GetPi() {
            return 3.14;
        }
    }

    interface ITest {
        void MethodOne();

        void MethodTwo();
    }

    interface ITest2:ITest {
        void Method3();
    }

    interface ITest3:ITest, ITest2 {
        void Method4();
    }

    class Test:ITest3 {
        public void MethodOne() {
            Console.WriteLine("1");
        }

        public void MethodTwo() {
            Console.WriteLine("2");
        }

        void ITest2.Method3() {
            Console.WriteLine("3");
        }

        void ITest3.Method4() {
            Console.WriteLine("4");
        }
    }
}
