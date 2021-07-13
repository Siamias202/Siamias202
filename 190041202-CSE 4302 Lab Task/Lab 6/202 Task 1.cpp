#include<bits/stdc++.h>
using namespace std;
class Counter
{
private:
    int Count,step;
public:
    Counter():Count(0),step(1)
    {

    }
    Counter(int a,int b):Count(a),step(b)
    {

    }
    void setIncrementStep(int step_val)
    {
        if(step_val<0)
        {
            cout<<"Negative value";
            return;
        }
        else step=step_val;
    }
    int getCount()
    {
        return Count;
    }
    void increment()
    {
        Count+=step;
    }
    void resetCount()
    {
        Count=0;
    }
    Counter operator +(Counter a)
    {
        return Counter(Count+a.Count,min(step,a.step));
    }



    Counter operator ++()
    {
        Count+=step;
        return Counter(Count,step);
    }

    Counter operator ++(int)
    {
        Count+=step;
        return Counter(Count,step);
    }
    Counter operator +=(Counter a)
    {
        return Counter(Count+a.Count, step);
    }

};

int main()
{
   Counter c1;
   c1.increment();
   Counter c2;
   c1.increment();
   Counter c3=c1+c2;
   cout<<c3.getCount()<<endl;
}
