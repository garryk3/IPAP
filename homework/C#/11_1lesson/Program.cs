using System;
using System.IO;

namespace _11_1lesson
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Logger logger = new Logger("log.txt");
            logger.Log("test1 message");
            logger.Log("test2 message");
            logger.Dispose();

            // variant 2  - dont need close stream
            using(Logger logger2 = new Logger("log.txt")) {
                logger2.Log("test11 message");
                logger2.Log("test22 message");
            }

            CarEngine engine = new CarEngine(22, 33);
            CarEngineSuper superEngine = new CarEngineSuper(224, 433);
            Car car = new Car(engine, superEngine);
            Car car2 = (Car)car.Clone();
        }
    }

    class Logger : IDisposable { 
        private StreamWriter writer;
        private bool dispose;

        public Logger(string fileName) {
            writer = new StreamWriter(fileName);
            dispose = false;
        }

        public void Log(string message) {
            writer.WriteLine(message);
        }

        public void Dispose() {
            if(dispose) {
                return;
            }
            writer.Close();
            dispose = true;
        }
    }

    class Car : ICloneable {
        private CarEngine engine;
        private CarEngineSuper engineSuper;

        public Car(CarEngine e1, CarEngineSuper e2) {
            engine = e1;
            engineSuper = e2;
        }

        public CarEngine Engine {
            get { return engine; }
            set { engine = value; }
        }

        public object Clone() {
            CarEngine cloneEngine = (CarEngine)engine.Clone();
            CarEngineSuper cloneEngineSuper = (CarEngineSuper)engineSuper.Clone();
            return new Car(cloneEngine, cloneEngineSuper) as Car;
        }
    }

    class CarEngine : ICloneable {
        private double arg1;
        private double arg2;

        public CarEngine(double a1, double a2) {
            arg1 = a1;
            arg2 = a2;
        }

        public double Arg1 {
            get { 
                return arg1; 
            }
        }

        public double Arg2 {
            get { 
                return arg2; 
            }
        }

        public object Clone() {
            return MemberwiseClone();
        }
    }


    class CarEngineSuper : ICloneable {
        private double arg1;
        private double arg2;

        public CarEngineSuper(double a1, double a2) {
            arg1 = a1;
            arg2 = a2;
        }

        public double Arg1 {
            get { 
                return arg1; 
            }
        }

        public double Arg2 {
            get { 
                return arg2; 
            }
        }

        public object Clone() {
            return MemberwiseClone();
        }
    }}
