#ifndef H_classIllusFriend
#define H_classIllusFriend

#include <iostream>

using namespace std;

class classIllusFriend
{
    friend void two(classIllusFriend cIFObject);

public:
    void print();
    void setx(int a);
private:
    int x;
}; // end class classIllusFriend

#endif // H_classIllusFriend
