#ifndef H_personType
#define H_personType

#include <string>

using namespace std;

class personType
{
public:
    void print() const; // Function to output the frst name and last name
    void setName(string first, string last);    //Function to set firstName and lastName according
    personType& setFirstName(string first);
    personType& setLastName(string last);
    string getFirstName() const;
    string getLastName() const;
    personType(string first = "", string last = "");

private:
    string firstName;
    string lastName;
}; // end class personType

#endif // H_personType
