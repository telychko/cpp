#include <initializer_list>
#include <iostream>

#include "lambda-functions.h"
#include "pack.h"
//#include "template-for-expansion.h"

class Copyable
{
public:
    Copyable(const Copyable &other) = delete;
    //{
    //    std::cout << "Copyable copied\n";
    //}

    //explicit 
    Copyable(std::initializer_list<int> poo)
    {
        std::cout << "Pupuseria\n";
    }
    Copyable(int i)
    {
        std::cout << "Direct initialized " << i << "\n";
        this->i = i;
    }
    int i;
};

Copyable fufa(Copyable a)
{
    std::cout << a.i << "\n";
    return {3};
}

int main()
{
    fufa({2});

    const Copyable &moo = 4, &coo = {4};

    //lambda();
    //zuza();
    //print_all(0, "32");
    std::cout<<"C++\n";
    return 0;
}
