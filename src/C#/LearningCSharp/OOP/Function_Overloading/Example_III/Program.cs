using System;

namespace FunctionOverloading{
    public static class ExampleThree{
        public static double getSquare(this double myObj){
            return Math.Pow(myObj, 2);
        }

        public static double getCube(this double myObj){
            return Math.Pow(myObj, 3);
        }
    }

    class MainProgram{
        static void Main(string[] args){
            double x = 10;
            System.Console.WriteLine(" [" + x + "] * [" + x + "] = " + x.getSquare());
            System.Console.WriteLine(" [" + x + "] * [" + x + "] * [" + x + "] = " + x.getCube());
        }
    }
}