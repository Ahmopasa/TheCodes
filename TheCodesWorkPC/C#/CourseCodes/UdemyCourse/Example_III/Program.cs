using System;
using System.Collections.Generic;

namespace UdemyCourse{
    class ExampleThree{
        static void Main(string[] args){
            Console.Write("Inside of Main()\n");
            greet("I am learing how to use methods in C_Sharp...\n");

            System.Console.Write("Please, enter integer numbers, up to ten, to find biggest one in-between them:");

            int[] numbers = new int[10];

            for (int i = 0; i < numbers.Length; i++)
            {
                numbers[i] = Convert.ToInt16(Console.ReadLine());
            }

            Console.Write("The Biggest One : {0}", findBiggest(numbers));
            Console.Write("The Lowest One  : {0}", findLeast(numbers));

        }

        static void greet(string text){
            Console.Write("Inside of greet()\n");
            System.Console.WriteLine("Hello!!!");
        }

        static bool findBiggest(int a, int b)
        {
            return a > b ? true : false;
        }

        static int findBiggest(int[] numbers)
        {
            int biggest = numbers[0];
            for (int i = 1; i < numbers.Length; i++)
            {
                if (!findBiggest(biggest, numbers[i]))
                {
                    biggest = numbers[i];
                }
            }

            return biggest;
        }

        static int findLeast(int[] numbers)
        {
            int lowest = numbers[0];
            for (int i = 1; i < numbers.Length; i++)
            {
                if (findBiggest(lowest, numbers[i]))
                {
                    lowest = numbers[i];
                }
            }

            return lowest;
        }
    }
}