template <int I, class T, class... R>
class TupleElement
{
    T item;
    TupleElement<sizeof...(R), R...> next;
};

template <class T, class... R>
class TupleElement<1, T, R...>
{
    T item;
};

template <class... T>
class Tuple
{
    TupleElement<sizeof...(T), T...> element;
};

int main(int, char**)
{
    Tuple<int, char, char> i;

    return 0;
}
