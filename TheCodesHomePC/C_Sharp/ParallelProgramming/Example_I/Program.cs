using System;
using System.Threading;

namespace ParallelProgramming{
    class ExampleOne{
        static void Main(string[] args){
            System.Console.WriteLine("a. Thread of Main() has started...");

            // A task to print to console:
            Task myMainTask = Task.Factory.StartNew(printConsole);
            //System.Console.WriteLine("b. Status of myMainTask : " + myMainTask.Status.ToString());
            // Wait until the process is done
            myMainTask.Wait();
            //System.Console.WriteLine("c. Status of myMainTask : " + myMainTask.Status.ToString());
            // Dispose the task
            myMainTask.Dispose();
            //System.Console.WriteLine("d. Status of myMainTask : " + myMainTask.Status.ToString());

            // A task to multiply two integer:
            Task mySubTask = Task.Factory.StartNew(
                                                    () => {
                                                        System.Console.WriteLine("Inside the lambda expression...");
                                                        System.Console.WriteLine("Result : " + multiplyTwoInteger(31, 32));
                                                    }
            );
            mySubTask.Wait();
            mySubTask.Dispose();

            System.Console.WriteLine("e. Thread of Main() has ended...");
        }

        static void printConsole(){
            System.Console.WriteLine("void ExampleOne::printConsole() has been called.");
        }

        static int multiplyTwoInteger(int valueOne, int valueTwo){
            System.Console.WriteLine("int ExampleOne::multiplyTwoInteger(int, int) has been called.");
            return valueOne * valueTwo;
        }
    }
}