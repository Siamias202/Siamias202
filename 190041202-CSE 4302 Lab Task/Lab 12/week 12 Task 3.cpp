#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 100; //array size


class Range
{
private:
    int index;

public:
    Range(int i) : index(i)
    {
    }
    int pos()
    {
        return index;
    }
};

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
            throw Range(n);
            exit(1);
        }
        return arr[n];
    }

};


int main()
{
    safearay<int> sa1;
    try
    {
        for (int j = 0; j < 101; j++) //insert elements
        {
            sa1[j] = j * 10; //*left* side of equal sign
        }
    }
    catch (Range &e)
    {
        cout << "Exception found : Array is out of bound" << endl;
        cout << "Exception at position " << e.pos() << endl;
    }

    for (int j = 0; j < LIMIT; j++) //display elements
    {
        int temp = sa1[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }

    safearay<double> sa2;
    try
    {
        for (int j = 0; j < LIMIT; j++) //insert elements
            sa2[j] = 100.564;//*left* side of equal sign

    }
    catch (Range &e)
    {
        cout << "Exception found : Array is out of bound" << endl;
        cout << "Exception at position " << e.pos() << endl;
    }
    for (int j = 0; j < LIMIT; j++) //display elements
    {
        double temp1 = sa2[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp1 << endl;
    }

    return 0;
}
