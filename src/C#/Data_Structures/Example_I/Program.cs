using System;

namespace DataStructures{
    public static class ExampleOne{
        public static void showElements(this System.Collections.IEnumerable iterator)
        {
            foreach (var item in iterator)
            {
                System.Console.WriteLine(item);
            }
        }
    }

    class MainProgram{
        static void Main(string[] args){
            List<string> myNameList = new List<string>();
            myNameList.Add("Ahmet");
            myNameList.Add("Kandemir");
            myNameList.Add("Pehlivanli");

            myNameList.showElements();

        }
    }
}