using System;
using System.Threading;

namespace ParallelProgramming{
    class ExampleFour{

        static int counterOne = 0;
        static int counterTwo = 10;
        static void Main(string[] args){
            System.Console.WriteLine("Main...");

            Parallel.Invoke(functionOne, functionTwo);

            System.Console.WriteLine("...Main");
        }

        static void functionOne(){
            for (int i = 0; i < 100; i++)
            {
                System.Console.WriteLine("Counter One : " + (counterOne++));
            }
        }

        static void functionTwo(){
            for (int i = 0; i < 10; i++)
            {
                System.Console.WriteLine("Counter Two : " + (counterTwo += 10));
            }
        }
    }
}