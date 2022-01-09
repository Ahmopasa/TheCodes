using System;
using System.Collections.Generic;

namespace HelloWorld
{
    class ExampleOne
    {
        static void Main(string[] args)
        {
            Console.Write("Enter an integer : ");
            int number = Convert.ToInt32(Console.ReadLine());
            
            printStar(number);
           
        }

        static void printStar(int number){
            for(int i = 0; i < number; )
            {
                if(i % 3 == 0)
                {
                    Console.Write("[*], ");
                    ++i;
                }
                Console.Write("[{0}], ", i++);
            }
        } 
    }
}
