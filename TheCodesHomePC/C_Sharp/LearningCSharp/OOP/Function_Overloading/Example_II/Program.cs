using System;

namespace FunctionOverloading{
    class FunctionOverloading{
        static void Main(string[] args){
            Console.WriteLine("Result : {0} ", add(100, 250)); // int add(int, int) was called : 350;Result : 350
            // Console.WriteLine("Result : {0} ", add(100.25, 250.25)); // cannot convert from 'double' to 'int'
            Console.WriteLine("Result : {0} ", add((float)100.25, (float)250.25)); // float add(float, float) was called : 350.5;Result : 350.5 
            Console.WriteLine("Result : {0} ", add(100.25f, 250.25f)); // float add(float, float) was called : 350.5;Result : 350.5 
        }

        static int add(int objOne, int objTwo){
            Console.Write("int add(int, int) was called : {0};", objOne + objTwo);
            return objOne + objTwo;
        }

        static float add(float objOne, float objTwo){
            Console.Write("float add(float, float) was called : {0};", objOne + objTwo);
            return objOne + objTwo;
        }
    }
}