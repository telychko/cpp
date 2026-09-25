#include <iostream>

#include "lambda-functions.h"
#include "pack.h"
//#include "template-for-expansion.h"

class Copyable
{
public:
    Copyable(const Copyable &other)
    {
        std::cout << "Copyable copied\n";
    }
    Copyable(int i)
    {
        std::cout << "Direct initialized " << i << "\n";
        this->i = i;
    }
    int i;
};

void fufa(Copyable a)
{
    std::cout << a.i << "\n";
}

int main()
{
    Copyable a(1);
    fufa(2);

    lambda();
    zuza();
    //print_all(0, "32");
    std::cout<<"C++\n";
    return 0;
}
