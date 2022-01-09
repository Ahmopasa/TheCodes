#include "Message.h"

int main(){
    
    Message greed{};
    greed("The Date of Today : 29.11.2021"); 

    Message wave{};
    wave.operator()("See you next time!");

    Message goodBye{};
    goodBye.handleID(101);

    std::cout << "Calling Message::operator int(). ID : " << (int)goodBye << "\n";
    ;
}