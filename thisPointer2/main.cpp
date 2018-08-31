#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

int main()
{
    personType student1("Angela", "Clodfelter");

    personType student2;

    personType student3;

    cout << "Sr-tudent 1: ";
    student1.print();
    cout << endl;

    student2.setFirstName("Shelly").setLastName("Malik");

    cout << "Student 2: ";
    student2.print();
    cout << endl;

    student3.setFirstName("Chelsea");

    cout << "Student 3: ";
    student3.print();
    cout << endl;

    student3.setLastName("Tomek");

    cout << "Student 3: ";
    student3.print();
    cout << endl;

    return 0;
}
