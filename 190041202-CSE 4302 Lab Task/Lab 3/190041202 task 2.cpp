#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
class RationalNumber
{
private:
    int numerator,denomerator;
public:
    void assign(int numerator,int denomerator)
    {
        if(denomerator==0)
        {
            cout<<"Error"<<endl;
            exit(1);
        }
        else
        {

            this->numerator=numerator;
            this->denomerator=denomerator;
        }
    }
    double convert()
    {
       return double(double(numerator)/double(denomerator));
    }

    void invert()
    {
        if(numerator==0)
        {
            cout<<"Error"<<endl;
            exit(1);

        }
        swap(numerator,denomerator);
    }
    void print()
    {
        cout<<"The rational Number is: "<<numerator<<"/"<<denomerator<<endl;
    }
};

int main()
{
    boost;
    RationalNumber r1;
    r1.assign(4,0);
    double res=r1.convert();
    cout<<res<<endl;
    r1.print();
    r1.invert();
    r1.print();


    RationalNumber r2;
    r2.assign(0,4);
    r2.invert();



}
