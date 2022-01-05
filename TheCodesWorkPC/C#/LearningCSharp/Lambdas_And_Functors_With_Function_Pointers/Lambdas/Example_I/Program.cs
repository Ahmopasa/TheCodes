using System;

namespace LambdaExpressions{
    class ExampleOne{
        static void Main(string[] args){           

            Func<int, int> myFunc = m_LambdaVariable => m_LambdaVariable * m_LambdaVariable;
            System.Console.WriteLine("25 * 25 = " + myFunc(25)); // 25 * 25 = 625

            Func<string, string> myFuncTwo = m_LambdaVariable => m_LambdaVariable + m_LambdaVariable;
            System.Console.WriteLine("Ahmet + Ahmet = " + myFuncTwo("Ahmet ")); // Ahmet + Ahmet = Ahmet Ahmet

            double firstLambdaParameter = 100.93;
            double secondLambdaParameter = 200.3993;
            
            Action<double, double> myAction = (firstLambdaParameter, secondLambdaParameter) => { System.Console.WriteLine(firstLambdaParameter + secondLambdaParameter); };
            myAction(firstLambdaParameter, secondLambdaParameter); // 301.3293
        }
    }
}