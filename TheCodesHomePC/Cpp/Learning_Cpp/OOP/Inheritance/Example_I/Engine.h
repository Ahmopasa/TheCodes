#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <iostream>

class Engine{
    public:
    Engine() 
    {
        std::cout << "[A ENGINE OBJECT HAS BEEN CREATED.]\n";
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Engine& engine)
    {
        return os << "* The volume : " << engine.m_Volume << "\n";
    }

    private:
    int m_Volume = 10;
};

#endif