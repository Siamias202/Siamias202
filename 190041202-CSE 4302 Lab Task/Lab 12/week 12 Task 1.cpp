#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 100; //array size
////////////////////////////////////////////////////////////////



template <class T>
class safearay
{
private:
    T arr[LIMIT];
    int position = 0;

public:
    T &operator[](int n) //note: return by reference
    {
        position = n;
        if (n < 0 || n >= LIMIT)
        {
            cout<<"\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }

};
////////////////////////////////////////////////////////////////
int main()
{
    safearay<int> sa1;

    for (int j = 0; j < 105; j++) //insert elements
    {
        sa1[j] = j * 10; //*left* side of equal sign
    }


    for (int j = 0; j < LIMIT; j++) //display elements
    {
        int temp = sa1[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }
    cout<<endl<<endl;
    safearay<double> sa2;
    for (int j = 0; j < LIMIT; j++) //insert elements
    {
        sa2[j] = j*10.56;
    }           //*left* side of equal sign
    for (int j = 0; j < LIMIT; j++) //display elements
    {
        double temp1 = sa2[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp1 << endl;
    }

    return 0;
}
