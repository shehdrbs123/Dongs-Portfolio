#include <iostream>
#include "yameList.h"

using namespace std;

int main()
{
    LinkedList l(100);

    l.insert(0,10);
    l.insert(0,20);

    l.erase(5);
    l.erase(0);

    l.traverse();

}