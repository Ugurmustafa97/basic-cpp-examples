#include <iostream>

using namespace std;

int main()
{
    int *list[100];

    try
    {
        for(int i = 0; i < 100; i++)
        {
            list[i] = new int[50000000];
            cout << "Created list[" << i
                 << "] of 50000000 components."
                 << endl;
        } // end for
    } // end try
    catch(bad_alloc be)
    {
        cout << "In the bad_alloc catch "
             << "block: " << be.what() << "."
             << endl;
    } // end catch

    return 0;
} // end main
