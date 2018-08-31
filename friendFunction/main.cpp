#include <iostream>
#include "classIllusFriend.h"

using namespace std;

int main()
{
    classIllusFriend aObject;

    aObject.setx(32);

    cout << "aObject.x: ";
    aObject.print();
    cout << endl;

    cout << "-*-*-*-*-*- Testig Friend Function "
         << "two -*-*-*- " << endl << endl;

    two(aObject);

    return 0;
}
