using System;
using System.Collections;
using System.Threading;
namespace Task
{
    class Task
    {
        private string taskname;
        public Task(string s)
        {
            taskname = s;
        }
        public void Execute()
        {
            Console.WriteLine(taskname);
        }
    }
    class Program
    {
        static Queue q = new Queue();
        static Thread executionThread =
        new Thread(new ThreadStart(ExecutionThread));
        static void ExecutionThread()
        {
            while (true)
            {
                Task t;
                lock (q)
                {
                    if (q.Count == 0)
                    {
                        continue;
                    }
                    t = (Task)q.Dequeue();
                }
                if (t == null)
                {
                    return;
                }
                t.Execute();
            }
        }
        static void Main(string[] args)
        {
            executionThread.Start();
            lock(q)
            {
                q.Enqueue(new Task("task #1"));
                q.Enqueue(new Task("task #2"));
                q.Enqueue(null);
            }
            while (true)
            {
                Thread.Sleep(10);
                lock (q)
                {
                    if (q.Count == 0)
                    {
                        break;
                    }
                }
            }
        }
    }
}
