#include "Message.h"

void Message::operator()(const std::string& message){
    std::cout << "Message::operator()() was called.\n";
    std::cout << "The message : " << message << "\n";
}

void Message::handleID(unsigned int ID)
{
    std::cout << "Message::handleID() was called.\n";
    m_ID = ID;
    std::cout << "The ID : " << m_ID << "\n";
}

Message::operator int() const
{
    return m_ID;
}
