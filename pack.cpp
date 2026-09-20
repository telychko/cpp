#include "pack.h"

//#include <iostream>
#include <utility>

// Metaprogramming template compile-time only feature
// Not be confused with Variadic arguments, ... at the end of function parameters

//  * a parameter pack
//      * template parameter pack
//        A template parameter pack is a template parameter that accepts zero or more template arguments
//        (non-types, types, or templates).
//        A template with at least one parameter pack is called a variadic template.
//      * function parameter pack
//        A function parameter pack is a function parameter that accepts zero or more function arguments.
//
//  * lambda init-capture pack (since C++20)
//
//  * structured binding pack (since C++26)
//
//  * A lambda init-capture pack is a lambda capture that introduces an init-capture for each of the elements
//    in the pack expansion of its initializer. (since C++20)
//
//  * A structured binding pack is an identifier in the structured binding declaration that introduces
//    zero or more structured bindings. (since C++26)
//
//  The number of elements of a pack is equal to:
//      * the number of arguments provided for the parameter pack,
//        if the pack is a template or function parameter pack,
//      * the number of elements in the pack expansion of its initializer,
//        if the pack is a lambda init-capture pack, (since C++20)
//      * structured binding size of the initializer less the number of non-pack elements
//        in the structured binding declaration, if the pack is a structured binding pack. (since C++26)

// sizeof... operator

// A non-type template parameter pack with an optional name
//type ... pack-name (optional)

// A type template parameter pack with an optional name
//type-parameter-key ... pack-name (optional)

// A constrained type template parameter pack with an optional name (since C++20)
//type-constraint ... pack-name (optional) (since C++20)

// A template template parameter pack with an optional name
//template < parameter-list > class ... pack-name (optional) (until C++17)
//template < parameter-list > type-parameter-key ... pack-name (optional) (since C++17)

// A function parameter pack with an optional name
//Function parameter pack (a form of declarator, appears in a function parameter list of a variadic function template)
//pack-name ... pack-param-name (optional)

// Pack expansion: expands to a list of zero or more patterns. The pattern must include at least one pack.
//Pack expansion (appears in a body of a template)
//pattern ...

// Template parameter pack

    class SimpleClass
    {
    };

    template <typename T>
    class ClassTemplate
    {
    };

    template <class, class> class C {};

    template<> class C<int,bool> {};

    template <template<class...> class...>
    class ClassPack
    {
    };

    typedef ClassTemplate<int> boo;
    template<class T> using goo=ClassTemplate<T>;

    //      * template parameter pack
    //        A template parameter pack is a template parameter that accepts zero or more template arguments
    //        (non-types, types, or templates).

    namespace
    {
        void mook()
        {
            ClassPack<ClassTemplate> p;
            (void)p;
        }
    }

// Function parameter pack

    namespace
    {
        template<typename T=int, typename... args>
        void f(args...){}

        // Variadic arguments
        void c(...){}

        void hook()
        {
            f("jj", 0);
        }
    }

// Lambda init-capture pack (since C++20)

template<typename... T>
void zozo(T... args)
{
    auto poo = [args...](auto... ts){};
}

void kozo()
{
    zozo(1);
}

// Structured binding pack (since C++26)
