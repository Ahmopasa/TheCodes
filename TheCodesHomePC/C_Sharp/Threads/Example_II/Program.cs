using System;
using System.Threading;

namespace Threads{
    class ExampleTwo{
        static void Main(string[] args){
            System.Console.WriteLine("[ Main Thread is about to start... ]");
            
            const int duty_cycle = 3;

            // A thread for "ThreadPiece::Run()"
            ThreadPiece workerOne = new ThreadPiece(duty_cycle, "WorkerOne");

            // A second thread for "ThreadPiece::Run()"
            ThreadPiece workerTwo = new ThreadPiece(duty_cycle, "WorkerTwo");

            // A third thread for "ThreadPiece::Run()"
            ThreadPiece workerThree = new ThreadPiece(duty_cycle, "WorkerThree");

            System.Console.WriteLine("[ Main Thread is about to end... ]");
        }
    }

    class ThreadPiece{
        public int m_count;

        public Thread m_threadObject;

        private int m_dutyCycle;
        
        public ThreadPiece(int dutyCycle, string name){
            m_count = 0;
            m_dutyCycle = dutyCycle;
            m_threadObject = new Thread(this.Run);
            m_threadObject.Name = name;
            m_threadObject.Start();
        }

        public void Run(){
            System.Console.WriteLine("[[ " + m_threadObject.Name + " is about to start... ]]");

            do
            {
                Thread.Sleep(250);
                System.Console.WriteLine("<< In " + m_threadObject.Name + ", Count : " + m_count + " >>");
                ++m_count; 
            } while (m_count < m_dutyCycle);

            System.Console.WriteLine("[[ " + m_threadObject.Name + " is about to terminate... ]]");
        }
    }
}