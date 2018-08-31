#ifndef H_thisPointerClass
#define H_thisPointerClass

#include <iostream>

using namespace std;

class thisPointerClass
{
public:
    void set(int a, int b, int c);
    void print() const;

    thisPointerClass updadeXYZ();

    thisPointerClass(int a = 0, int b = 0, int c = 0);

private:
    int x;
    int y;
    int z;
}; // end class thisPointerClass

#endif // H_thisPointerClass
