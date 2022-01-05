using System;
using System.Collections.Generic;

namespace MetaProgramming
{
    class MainClass{
        static void Main(string[] args)
        {           
            const int objectIntOne = 100;
            const int objectIntTwo = 200;
            Add<int> myIntAdder = new Add<int>(addInts);
            System.Console.WriteLine("Adding ints to each oter : " + "[" + objectIntOne + "] + [" + objectIntTwo + "] = " + myIntAdder(objectIntOne,objectIntTwo));         

            const float objectFloatOne = 100.015f;
            const float objectFloatTwo = 200.025f;
            Add<float> myFloatAdder = new Add<float>(addFloats);
            System.Console.WriteLine("Adding floats to each oter : " + "[" + objectFloatOne + "] + [" + objectFloatTwo + "] = " + myFloatAdder(objectFloatOne,objectFloatTwo));  

            const string objectStringOne = "Ulya";
            const string objectStringTwo = "Yuruk";
            Add<string> myStringAdder = new Add<string>(addStrings);
            System.Console.WriteLine("Adding strings to each oter : " + "[" + objectStringOne + "] + [" + objectStringTwo + "] = " + myStringAdder(objectStringOne,objectStringTwo));  
        }

        delegate T Add<T>(T variableOne, T variableTwo);

        static int addInts(int objectOne, int objectTwo)
        {
            return objectOne + objectTwo;
        }

        static float addFloats(float objectOne, float objectTwo)
        {
            return objectOne + objectTwo;
        }

        static string addStrings(string objectOne, string objectTwo)
        {
            return objectOne + " " + objectTwo;
        }
    }
}