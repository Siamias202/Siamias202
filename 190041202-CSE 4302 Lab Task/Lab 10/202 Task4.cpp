#include<bits/stdc++.h>
using namespace std;


class Distance
{
private:
    int *feet_ptr;
    int *inches_ptr;
public:
    Distance(int f=0,int i=0)
    {
        feet_ptr=new int(f);
        inches_ptr=new int(i);
    }

    void setvalue(int f,int i)
    {
        *feet_ptr=f;
        *inches_ptr=i;
    }

    void show()
    {
        cout<<"Feet:"<<*feet_ptr<<" Inches:"<<*inches_ptr<<endl;
    }
};


int main()
{
    Distance d1(3,4);
    d1.show();
    Distance d2;
    d2=d1;
    d2.show();

    d1.setvalue(5,6);
    d2.show();//Both pointer of object d1 and d2 are pointing to same address

}
