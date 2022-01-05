using System;
using System.Threading;

namespace ParallelProgramming{
    class ExampleTwo{
        static int generalCounter = 0;
        static void Main(string[] args){
            System.Console.WriteLine("ON  - ParallelProgramming::ExampleTwo::Main() has started working.");

            Task stageOneTask = Task.Factory.StartNew(myTaskStageOne);

            Task stageTwoTask = stageOneTask.ContinueWith(myTaskStageTwo);

            stageTwoTask.Wait();

            stageOneTask.Dispose();
            stageTwoTask.Dispose();

            System.Console.WriteLine("OFF - ParallelProgramming::ExampleTwo::Main() has stopped working.");
        }

        static void myTaskStageOne(){
            System.Console.WriteLine("ON  - ParallelProgramming::ExampleTwo::myTaskStageOne() has started working.");

            for(int i = 0; i < 5; ++i){
                Thread.Sleep(250);
                System.Console.WriteLine("General Counter : " + (++generalCounter));
            }

            System.Console.WriteLine("OFF - ParallelProgramming::ExampleTwo::myTaskStageOne() has stopped working.");
        }

        static void myTaskStageTwo(Task tempTask){
            System.Console.WriteLine("ON  - ParallelProgramming::ExampleTwo::myTaskStageTwo() has started working.");

            for(int i = 0; i < 5; ++i){
                Thread.Sleep(500);
                System.Console.WriteLine("General Counter : " + (++generalCounter));
            }

            System.Console.WriteLine("OFF - ParallelProgramming::ExampleTwo::myTaskStageTwo() has stopped working.");
        }
    }
}