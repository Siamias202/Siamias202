#include<bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;
public:
    Rectangle(double length,double width)
    {
        this->length=length;
        this->width=width;
    }

    Rectangle()
    {
        length=1;
        width=1;
    }

    void set_length(double length)
    {
        if(length>=1.0 && length<=20)
        {
            this->length=length;
        }
    }

    double get_length()
    {
        return this->length;
    }

    void perimeter()
    {
        cout<<"Perimeter is: "<<2*(length+width)<<endl;
    }
    void area()
    {
        cout<<"Area is: "<<length*width<<endl;
    }

    void diagonal()
    {
        double result=length*length+width*width;
        cout<<"Diagonal is:";
        cout<<sqrt(result)<<endl;
    }

    void angle()
    {
         double result=length*length+width*width;
         double res=sqrt(result);
         double a=acos(length/res)*(180/3.1415);
         cout<<"Angle is:";
         cout<<a<<endl;
    }

};

int main()
{
    Rectangle r1;
    r1.diagonal();
    r1.perimeter();
    r1.area();
    r1.angle();

}
