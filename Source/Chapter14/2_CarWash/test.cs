using System;
using System.Collections.Generic;
using System.Threading;
namespace CarWash
{
    class Car
    {
        private string CarName;
        public override string ToString()
        CHAPTER 14 Å° GENERICS 239
        {
            return CarName;
        }
        public Car(string s)
        {
            CarName = s;
        }
    }
    class Program
    {
        static Queue<Car> washQueue = new Queue<Car>();
        static Queue<Car> vacuumQueue = new Queue<Car>();
        static Thread WashThread = new Thread(new ThreadStart(Wash));
        static Thread VacuumThread = new Thread(new ThreadStart(Vacuum));
        static void Wash()
        {
            for (; true; Thread.Sleep(10))
            {
                Car c;
                lock (washQueue)
                {
                    if (washQueue.Count == 0)
                    {
                        continue;
                    }
                    c = washQueue.Dequeue();
                }
                if (c == null)
                {
                    break;
                }
                Console.WriteLine("-Starting Wash of {0}", c);
                Thread.Sleep(1300);
                Console.WriteLine("-Completing Wash of {0}", c);
            }
        }
        static void Vacuum()
        {
            for (;true;Thread.Sleep(10))
            {
                Car c;
                lock(vacuumQueue)
                {
                    if (vacuumQueue.Count == 0)
                    {
                        continue;
                    }
                    c = vacuumQueue.Dequeue();
                }
                if (c != null)
                {
                    Console.WriteLine("+Starting Vacuum of {0}", c);
                    Thread.Sleep(1000);
                    Console.WriteLine("+Completing Vacuum of {0}", c);
                }
                lock (washQueue)
                {
                    washQueue.Enqueue(c);
                }
                if (c == null)
                {
                    break;
                }
            }
        }
        static void Main(string[] args)
        {
            VacuumThread.Start();
            WashThread.Start();
            lock (vacuumQueue)
            {
                vacuumQueue.Enqueue(new Car("Volvo"));
                vacuumQueue.Enqueue(new Car("VW"));
                vacuumQueue.Enqueue(new Car("Jeep"));
                vacuumQueue.Enqueue(null);
            }
            while (VacuumThread.IsAlive || WashThread.IsAlive)
            {
                Thread.Sleep(10);
            }
        }
    }
}
