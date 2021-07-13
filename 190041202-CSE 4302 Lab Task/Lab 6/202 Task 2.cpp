#include<bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    float abscissa=0.0;
    float ordinate=0.0;
public:
    Coordinate()
    {
        this->abscissa=0.0;
        this->ordinate=0.0;
    }
    Coordinate(float x,float y)
    {
        this->abscissa=x;
        this->ordinate=y;
    }

    float getDistance(Coordinate c)
    {
        float ans=(this->abscissa-c.abscissa)*(this->abscissa-c.abscissa) + (this->ordinate-c.ordinate)*(this->ordinate-c.ordinate);
        float res=sqrt(ans)*1.00;
        return res;
    }

    float getDistance()
    {
        float ans=(this->abscissa*this->abscissa)+(this->ordinate*this->ordinate);
        float res=sqrt(ans)*1.00;
        return res;
    }

    void move_x(float val)
    {
        this->abscissa+=val;
    }

    void move_y(float val)
    {
        this->ordinate+=val;
    }

    Coordinate operator++()
    {
       return Coordinate(++this->abscissa,++this->ordinate);
    }
    Coordinate operator++(int)
    {
        return Coordinate(this->abscissa++,this->ordinate++);
    }
    Coordinate operator--()
    {
        return Coordinate(--this->abscissa,--this->ordinate);
    }
    Coordinate operator--(int)
    {
        return Coordinate(this->abscissa--,this->ordinate--);
    }

    bool operator < (Coordinate c) const
    {
        float ans1=abscissa*abscissa+ordinate*ordinate;
        float f1=sqrt(ans1);

        float ans2=c.abscissa*c.abscissa+c.ordinate*c.ordinate;
        float f2=sqrt(ans2);

        return (f1<f2)?true:false;
    }

    bool operator > (Coordinate c) const
    {
        float ans1=abscissa*abscissa+ordinate*ordinate;
        float f1=sqrt(ans1);

        float ans2=c.abscissa*c.abscissa+c.ordinate*c.ordinate;
        float f2=sqrt(ans2);

        return (f1>f2)?true:false;
    }

    bool operator <= (Coordinate c) const
    {
        float ans1=abscissa*abscissa+ordinate*ordinate;
        float f1=sqrt(ans1);

        float ans2=c.abscissa*c.abscissa+c.ordinate*c.ordinate;
        float f2=sqrt(ans2);

        return (f1<=f2)?true:false;
    }

     bool operator >= (Coordinate c) const
    {
        float ans1=abscissa*abscissa+ordinate*ordinate;
        float f1=sqrt(ans1);

        float ans2=c.abscissa*c.abscissa+c.ordinate*c.ordinate;
        float f2=sqrt(ans2);

        return (f1>=f2)?true:false;
    }

     bool operator == (Coordinate c) const
    {
        float ans1=abscissa*abscissa+ordinate*ordinate;
        float f1=sqrt(ans1);

        float ans2=c.abscissa*c.abscissa+c.ordinate*c.ordinate;
        float f2=sqrt(ans2);

        return (f1==f2)?true:false;
    }

     bool operator != (Coordinate c) const
    {
        float ans1=abscissa*abscissa+ordinate*ordinate;
        float f1=sqrt(ans1);

        float ans2=c.abscissa*c.abscissa+c.ordinate*c.ordinate;
        float f2=sqrt(ans2);

        return (f1!=f2)?true:false;
    }







    void display()
    {
        cout<<"Abscissa is: "<<this->abscissa<<endl;
        cout<<"Ordinate is: "<<this->ordinate<<endl;
    }

    ~Coordinate()
    {

    }


};

int main()
{
    Coordinate c1(1,1),c2(-1,-1);
    if(c1!=c2)
    {
        cout<<"C1 is  not equal  C2"<<endl;
    }
    else
    {
        cout<<"C1 is equal"<<endl;
    }



}
