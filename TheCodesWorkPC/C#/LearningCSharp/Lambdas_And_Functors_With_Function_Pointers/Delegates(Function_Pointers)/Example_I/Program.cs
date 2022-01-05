using System;

namespace Delegates
{
    class ExampleOne
    {
        delegate int myFunctionPointer(int x, int y);

        static void Main(string[] args)
        {
            myFunctionPointer myFuncPtr = Add;
            Console.Write("[ int Add(int, int) ] was called. Result : " + myFuncPtr(100, 200));
        }
        
        static public int Add(int x, int y)
        {
            return x + y;
        }
    }
}