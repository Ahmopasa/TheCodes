using System;
using System.Threading;

namespace Threads{
    class ExampleThree{
        static void Main(string[] args)
        {
            const int dutyCycle = 100;
            Thread workerOne = new Thread(
                                        () => miniPrinter(dutyCycle, ".")
                                    );
            workerOne.Start();

            Thread workerTwo = new Thread (
                                        () => miniPrinter(dutyCycle, "*")
                                    );
            workerTwo.Start();

            Thread workerThree = new Thread (
                                        () => miniPrinter(dutyCycle, "#")
                                    );
            workerThree.Start();


        }

         static void miniPrinter(int dutyCycle, string objToPrint)
         {
            System.Console.Write("[ " + objToPrint + " ] => ");
            for (int i = 0; i < dutyCycle; i++)
            {
                System.Console.WriteLine(objToPrint);
            }
        }
    }
}