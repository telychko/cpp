#include "lambda-functions.h"

#include <iostream>

class Copiable
{
public:
    Copiable() = default;
    Copiable(const Copiable& other)
    {
        (void)other;
        std::cout << "Lambda Copiable copied\n";
    }
};

void lambda()
{
    Copiable poopa;
    auto roo = [=](){
        std::cout << "Closure\n" << &poopa;
    };
    auto zoo = roo;

    zoo();
}
