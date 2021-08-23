#include<bits/stdc++.h>
using namespace std;

class Base
{
private:
    int x;
    Base(const Base& temp)
    {
        x=temp.x;
    }

    Base &operator=(const Base &temp)
    {
        x=temp.x;
        return *this;
    }

public:
    Base(int i=0)
    {
        x=i;
    }

    void show()
    {
        cout<<x<<endl;
    }
};

int main()
{
    Base b1(10);
    b1.show();
    Base b2=b1;
    b2.show();
}
