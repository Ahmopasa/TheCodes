using System;

class ExampleOne{
    static void Main(string[] args)
    {
        Console.Write("*************************\n");
        Toyota myToyota = new Toyota();
        myToyota.setEngineVolume(900);
        Console.Write("myToyota engine Volume : " + myToyota.getEngineVolume() + "\n");
        myToyota.startEngine();
        myToyota.idle();
        myToyota.drive();
        myToyota.stopEngine();
        Console.Write("*************************\n");
        Mazda myMazda = new Mazda();
        myMazda.setEngineVolume(1250);
        Console.Write("myMazda engine Volume : " + myMazda.getEngineVolume() + "\n");
        myMazda.startEngine();
        myMazda.idle();
        myMazda.drive();
        myMazda.stopEngine();
        Console.Write("*************************\n");
    }
}