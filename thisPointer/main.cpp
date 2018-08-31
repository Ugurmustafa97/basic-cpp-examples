#include <iostream>
#include "thisPointerClass.h"

using namespace std;

int main()
{
    thisPointerClass object1(3, 5, 7);
    thisPointerClass object2;

    cout << "Object 1: ";
    object1.print();

    object2 = object1.updadeXYZ();

    cout << "After updating object1: ";
    object1.print();

    cout << "Object 2: ";
    object2.print();

    return 0;
}
