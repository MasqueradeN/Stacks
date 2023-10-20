#include <iostream>
#include "Stack.hpp"

int main()
{
    Stack<int> list(5);

    list.Push(10);
    list.Push(54);
    list.Push(45);

    while (list.IsEmpty() == false)
    {
        std::cout << list.Top();
        list.Pop();
        //Este todavía no funciona al 100% pero yo iba por un muy buen camino, parece que solo me falta el Pop() pero ni idea xd
        //Esencialmente teníamos que pasar los array que hicmios la primera clase a los array que utilizamos para los stacks 
    }
}
