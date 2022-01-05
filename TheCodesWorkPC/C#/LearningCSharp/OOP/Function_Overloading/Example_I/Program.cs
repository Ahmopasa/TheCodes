using System;

class Box{
    public int size = 2;
}

class FunctionOverloading{
    static void Main(string[] args){
        seperator();
        greedKindly(name :"Ahmet", surname: "Kandemir");
        seperator();
        //....integer......//
        int x = 100;
        int y = x / 2;
        Console.WriteLine("Before calling any function         => x : " + x + ", y : " + y);
        seperator();
        Console.WriteLine("Before calling callByValue(x,y)     => x : " + x + ", y : " + y);
        callByValue(x,y);
        Console.WriteLine("After calling callByValue(x,y)      => x : " + x + ", y : " + y);
        seperator();
        Console.WriteLine("Before calling callByReference(ref x, ref y)    => x : " + x + ", y : " + y);
        callByReference(ref x, ref y);
        Console.WriteLine("After calling callByReference(ref x, ref y)     => x : " + x + ", y : " + y);
        seperator();
        //....string.....//
        string name = "Ulya";
        string surname = "Yuruk";
        Console.WriteLine("Before calling callByValue(name, surname) => name : " + name + ", surname : " + surname);
        callByValue(name,surname);
        Console.WriteLine("After calling callByValue(name, surname) => name : " + name + ", surname : " + surname);
        seperator();
        Console.WriteLine("Before calling callByReference(ref name, ref surname) => name : " + name + ", surname : " + surname);
        callByReference(ref name, ref surname);
        Console.WriteLine("After calling callByReference(ref name, ref surname) => name : " + name + ", surname : " + surname);
        seperator();
        //....Box.......//
        Box objectOne = new Box();
        Console.WriteLine("Before calling callByValue(objectOne) => size : " + objectOne.size);
        callByValue(objectOne);
        Console.WriteLine("After calling callByValue(objectOne) => size : " + objectOne.size);
        seperator();
        Console.WriteLine("Before calling callByReference(ref objectOne) => size : " + objectOne.size);
        callByReference(ref objectOne);
        Console.WriteLine("After calling callByReference(ref objectOne) => size : " + objectOne.size);
        seperator();
    }
    static void seperator(){
        Console.Write("\n****************************\n");
    }

    static void greed(string text){
        Console.WriteLine(text);
    }

    static void greedKindly(string name, string surname){
        Console.Write("Welcome, " + name + " " + surname + ".\n");
        greed("It's good to see you!");
        seperator();
    }
    static void callByValue(int x, int y)
    {
        ++x;
        ++y;
        Console.WriteLine("Inside of callByValue(int x, int y) => x : " + x + ", y : " + y);
    }
    static void callByValue(string x, string y)
    {
        x = "NewName";
        y = "NewName";
        Console.WriteLine("Inside of callByValue(string x, string y) => x : " + x + ", y : " + y);
    }
    static void callByValue(Box objectOne)
    {
        objectOne.size = 10;
        Console.WriteLine("Inside of callByValue(Box objectOne) => size : " + objectOne.size);
    }
    static void callByReference(ref int x, ref int y)
    {
        ++x;
        ++y;
        Console.WriteLine("Inside of callByReference(ref int x, ref int y) => x : " + x + ", y : " + y);
    }
    static void callByReference(ref string x, ref string y)
    {
        x = "RefNewName";
        y = "RefNewName";
        Console.WriteLine("Inside of callByValue(string x, string y) => x : " + x + ", y : " + y);
    }
    static void callByReference(ref Box objectOne)
    {
        objectOne.size = 20;
        Console.WriteLine("Inside of callByValue(Box objectOne) => size : " + objectOne.size);
    }
}