using System;

class Mazda : Cars{
    public override void startEngine()
    {
        Console.Write("Mazda Engine has just started...\n");
    }

    public override void drive()
    {
        Console.Write("Mazda Engine has started moving. Acceleration is " + 6.28f + "\n");
    }

    public override void idle()
    {
        Console.Write("Mazda Engine has stopped moving...\n");
    }

    public override void stopEngine()
    {
        Console.Write("Mazda Engine is waiting idly...\n");
    }

    public override int getEngineVolume()
    {
        return base.getEngineVolume();
    }

    public override void setEngineVolume(int engineVolume)
    {
        if (engineVolume >= 2500)
        {
            base.setEngineVolume(engineVolume);
        }
        else
        {
            base.setEngineVolume(engineVolume);
        }
    }

}