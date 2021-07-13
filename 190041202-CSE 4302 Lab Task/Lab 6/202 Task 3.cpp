#include<bits/stdc++.h>
using namespace std;

class FLOAT
{
private:
    float f1;
public:
    FLOAT()
    {
        f1=0.0;
    }
    FLOAT(float f)
    {
        f1=f;
    }

    void display()
    {
        cout<<"Value of Float : "<<f1<<endl;
    }

    float operator +(FLOAT f2)
    {
        float ans=f1+f2.f1;
        return ans;
    }

    float operator -(FLOAT f2)
    {
        float ans=f1-f2.f1;
        return ans;
    }

    float operator *(FLOAT f2)
    {
        float ans=f1*f2.f1;
        return ans;
    }

    float operator /(FLOAT f2)
    {
        float ans=f1/f2.f1;
        return ans;
    }
};

int main()
{
    FLOAT f1(2.5);
    FLOAT f2(3.1);

    cout<<f1+f2<<endl;
    cout<<f1-f2<<endl;
    cout<<f1*f2<<endl;
    cout<<f1/f2<<endl;

}
