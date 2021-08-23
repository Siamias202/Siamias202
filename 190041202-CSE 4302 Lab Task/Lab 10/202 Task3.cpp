//Assignment operator and default copy constructor

#include<bits/stdc++.h>
using namespace std;


class Distance
{
private:
    int feet;
    int inches;

public:

    Distance(int f=0,int i=0)
    {
        feet=f;
        inches=i;
    }
    void displayDistance()
    {
        cout << "Feet:"<< feet <<  " Inch:" <<  inches << endl;
    }
};

int main()
{
    //Assignment Operator
    Distance d1(2,4);

    Distance d2=d1;
    d2.displayDistance();


    //Copy constructor

    Distance d3(d1);
    d1.displayDistance();

}
