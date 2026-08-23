#include <cstdio>
#include <typeinfo>
#include <iostream>
#include <cxxabi.h>

struct A
{
    int a;
};

struct B
{
    B(): a(123){}
    int a;
    void f(int i, double d)
    {
        std::cout<<"B::f() "<<i<<" "<<a<<" "<<d<<std::endl;
    }
    void f1(){}
};

struct C : A, B
{
    int d;
};

void demangle(const char *name)
{
    char buf[256];
    size_t len = sizeof(buf);
    abi::__cxa_demangle(name, buf, &len, 0);
    std::cout<<buf<<std::endl;
}

// c++11
//
//template <typename... P>
//struct ObjPtr
//{
//    template <typename T, typename M>
//    void bind(T *obj, void (M::*m)(P...))
//    {
//        this->obj = reinterpret_cast<ObjPtr*>(static_cast<M*>(obj));
//        meth = reinterpret_cast<void (ObjPtr::*)(P...)>(m);
//    }

//    void operator()(P... p)
//    {
//        (obj->*meth)(p...);
//    }

//    ObjPtr *obj;
//    void (ObjPtr::*meth)(P...);
//};

template <typename P1 = char, typename P2 = char, typename P3 = char, typename P4 = char  >
struct ObjPtr
{
    template <typename T, typename M>
    void bind(T *obj, void (M::*m)())
    {
        this->obj = reinterpret_cast<ObjPtr*>(static_cast<M*>(obj));
        meth = reinterpret_cast<void (ObjPtr::*)(P1,P2,P3,P4)>(m);
    }
    template <typename T, typename M>
    void bind(T *obj, void (M::*m)(P1))
    {
        this->obj = reinterpret_cast<ObjPtr*>(static_cast<M*>(obj));
        meth = reinterpret_cast<void (ObjPtr::*)(P1,P2,P3,P4)>(m);
    }
    template <typename T, typename M>
    void bind(T *obj, void (M::*m)(P1,P2))
    {
        this->obj = reinterpret_cast<ObjPtr*>(static_cast<M*>(obj));
        meth = reinterpret_cast<void (ObjPtr::*)(P1,P2,P3,P4)>(m);
    }
    template <typename T, typename M>
    void bind(T *obj, void (M::*m)(P1,P2,P3))
    {
        this->obj = reinterpret_cast<ObjPtr*>(static_cast<M*>(obj));
        meth = reinterpret_cast<void (ObjPtr::*)(P1,P2,P3,P4)>(m);
    }
    template <typename T, typename M>
    void bind(T *obj, void (M::*m)(P1,P2,P3,P4))
    {
        this->obj = reinterpret_cast<ObjPtr*>(static_cast<M*>(obj));
        meth = reinterpret_cast<void (ObjPtr::*)(P1,P2,P3,P4)>(m);
    }

    void operator()(P1 p1 = 0, P2 p2 = 0, P3 p3 = 0, P4 p4 = 0)
    {
        (obj->*meth)(p1, p2, p3, p4);
    }

    ObjPtr *obj;
    void (ObjPtr::*meth)(P1,P2,P3,P4);
};

// method qualifier syntax
// address of methods can be obtained only &T::method
//
// method syntax, method pointer syntax T::method T::*method
// void T::(), void (T::*)()

// Test:
//{
//    C c;
//    ObjPtr<int, double> p, d;
//    p.bind(&c, &C::f);
//    p(5);
//
//    d = p;
//
//    d(8, 2.3);
//    return 0;
//}
