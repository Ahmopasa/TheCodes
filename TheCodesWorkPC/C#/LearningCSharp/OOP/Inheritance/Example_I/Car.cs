using System;

abstract class Cars{
    public abstract void startEngine();
    public abstract void drive();
    public abstract void idle();
    public abstract void stopEngine();
    
    public virtual int getEngineVolume()
    {
        return m_engineVolume;
    }
    public virtual void setEngineVolume(int engineVolume)
    {
        if(engineVolume >= 1000)
            m_engineVolume = engineVolume;
        else   
            m_engineVolume = 999;
    }

    private int m_engineVolume;

}