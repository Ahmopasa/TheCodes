using System;

namespace ActionAndFunc{
    class ExampleOne{
        static void Main(string[] args){
            // Action
            Action<int, string> myActionObject = new Action<int, string>(userInfo);
            myActionObject(28, "Ahmet Kandemir Pehlivanli");

            // Func
            Func<DateTime, double> myFuncObject = new Func<DateTime, double>(daysSinceBirth);
            double totalDays = myFuncObject(new DateTime(1993, 9, 17));
            System.Console.WriteLine("[ " + totalDays + " ] has passed since your birth.");
        }

        static void userInfo(int userID, string nameSurname){
            System.Console.WriteLine("ID           : " + userID);
            System.Console.WriteLine("Name Surname : " + nameSurname);
        }

        static double daysSinceBirth(DateTime birthDate){
            return (DateTime.Now - birthDate).TotalDays;
        }
    }
}