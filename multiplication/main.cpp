#include <iostream>

using namespace std;

int main()
{
    int A[4] = {1,2,3,4};
    int B[4] = {1,2,3,4};
    long int result[];
    int i,j;

    for(i=0;i=3;i++)
        for(j=0;j=3;j++)
        {
            {
                result[i] = B[3-i] * A[j];
            } // end for
        }

    int a;
    for(a=0;a=3;a++)
    {
        cout << result[a] << endl;
    }
}
