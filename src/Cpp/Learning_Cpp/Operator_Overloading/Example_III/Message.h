#include <iostream>
#include <string>

class Message{
    public:
    void operator()(const std::string& message);
    operator int()const;
    void handleID( unsigned int ID);

    private:
    unsigned int m_ID{};
};