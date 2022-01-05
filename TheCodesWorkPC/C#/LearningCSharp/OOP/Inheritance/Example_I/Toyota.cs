using System;

class Toyota : Cars{
    public override void startEngine()
    {
        Console.Write("Toyota Engine has just started...\n");
    }

    public override void drive()
    {
        Console.Write("Toyota Engine has started moving. Acceleration is " + 3.14f + "\n");
    }

    public override void idle()
    {
        Console.Write("\nToyota Engine has stopped moving...\n");
    }

    public override void stopEngine()
    {
        Console.Write("\nToyota Engine is waiting idly...\n");
    }

    public override int getEngineVolume()
    {
        return base.getEngineVolume();
    }

    public override void setEngineVolume(int engineVolume)
    {
        if (engineVolume >= 1500)
        {
            base.setEngineVolume(engineVolume);
        }
        else
        {
            base.setEngineVolume(engineVolume);
        }
    }

    //private int m_engineVolume;
}