using System;

namespace UdemyCourse
{
    class ExampleOne
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!!!\nIt's my first C-Sharp project.\n");
            int myAge = 28;
            int herAge = 26;

            var totalAge = myAge + herAge;

            Console.Write("Total Age : {0}", totalAge);
        }
    }
}