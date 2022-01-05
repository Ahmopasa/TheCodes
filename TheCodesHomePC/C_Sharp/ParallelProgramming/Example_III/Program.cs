using System;
using System.Threading;

namespace ParallelProgramming{
    class ExampleFour{
        static int generalCounter = 0;
        static void Main(string[] args){
            Task<bool> stageOneTask = Task<bool>.Factory.StartNew
                                                                (    
                                                                    () => { if (stageOneTaskFunction(5))
                                                                            {
                                                                                System.Console.WriteLine("Stage - I is completed.");
                                                                                return true;
                                                                            } 
                                                                            else
                                                                            {
                                                                                return false;
                                                                            }
                                                                        }
                                                                );

            Task<bool> stageTwoTask = stageOneTask.ContinueWith(stageTwoTaskFunction);
            if (stageTwoTask.Result == true)
            {
                System.Console.WriteLine("Stage - II is completed.");
                stageTwoTask.Dispose();
            }

            stageOneTask.Dispose();    
        }

        static bool stageOneTaskFunction(int maxSize){
            for (int i = 0; ; )
            {
                generalCounter += 3;

                System.Console.WriteLine("General Counter : " + generalCounter);

                if (i == maxSize)
                {
                    return true;
                }
                else
                {
                    ++i;
                }
            }
        }

        static bool stageTwoTaskFunction(Task tempTask){
            while(generalCounter > 0)
            {
                generalCounter -= 3;

                System.Console.WriteLine("General Counter : " + generalCounter);
            }

            return true;
        }
    }
}