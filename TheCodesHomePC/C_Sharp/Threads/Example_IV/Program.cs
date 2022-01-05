using System;
using System.Threading;

namespace Threads{
    class ExampleFour{
        static void Main(string[] args){
            CustomClass myCustomClassObj = new CustomClass(31, 32);
            Thread myCustomClassThread = new Thread(new ParameterizedThreadStart(AddValues));
            myCustomClassThread.Start(myCustomClassObj);
        }

        static void AddValues(object data){
            if (data is CustomClass)
            {
                System.Console.WriteLine("ID of thread in main()   : {0}", Thread.CurrentThread.ManagedThreadId);
                System.Console.WriteLine("Name of thread in main() : " + Thread.CurrentThread.Name);
                CustomClass myCustomClassObj = (CustomClass)data;
                System.Console.WriteLine("{0} + {1} = {2}", myCustomClassObj.a, myCustomClassObj.b, myCustomClassObj.a + myCustomClassObj.b);
            }
        }
    }

    class CustomClass{
        public int a;
        public int b;

        public CustomClass(int valueOne, int valueTwo){
            a = valueOne;
            b = valueTwo;
        }
    }
}