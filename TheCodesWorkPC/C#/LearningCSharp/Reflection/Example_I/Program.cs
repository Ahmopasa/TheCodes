using System;
using System.Reflection;

namespace Reflection{
    class ExampleOne{
        static void Main(string[] args){
            System.Console.WriteLine("***************************");
            string path = @"D:\CollectiveCodes\C#\Reflection\Example_I\bin\Debug\net6.0\Example_I.dll";
            Assembly myAssemblyObjOne = Assembly.LoadFile(path);
            showAssemblyInfo(myAssemblyObjOne);
            System.Console.WriteLine("***************************");
            Assembly myAssemblyObjTwo = Assembly.GetExecutingAssembly();
            showAssemblyInfo(myAssemblyObjTwo);
            System.Console.WriteLine("***************************");
        }

        static void showAssemblyInfo(Assembly assemblyObj){
            System.Console.WriteLine("-----------------------");
            System.Console.WriteLine(assemblyObj.FullName); // Example_I, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
            System.Console.WriteLine("GAC Status : " + (assemblyObj.GlobalAssemblyCache ? "True" : "False")); // GAC Status : False
            System.Console.WriteLine("Path       : " + assemblyObj.Location); // Path       : D:\CollectiveCodes\C#\Reflection\Example_I\bin\Debug\net6.0\Example_I.dll
            System.Console.WriteLine("Version    : " + assemblyObj.ImageRuntimeVersion); // Version    : v4.0.30319
            System.Console.WriteLine("-----------------------");
        }
    }
}