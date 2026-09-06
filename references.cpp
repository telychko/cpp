#include "references.h"

#include <utility>

// std::move
void f1(int &&a)
{
    (void)a;
}
void f2(int &&a)
{
    f1(std::move(a));
}

// Forwarding references std::forward
template<typename T>
void f3(T &&a)
{
    f1(std::forward(a));
}
