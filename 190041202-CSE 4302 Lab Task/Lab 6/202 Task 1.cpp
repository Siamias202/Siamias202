
#include <iostream>
using namespace std;

class Counter
{
private:
    int count,add;
public:

    Counter():count(0),add(1)
    {

    }

    Counter(int c, int a):count(c),add(a)
    {

    }

    void setIncrementStep(int step_val=1)
    {
        if(step_val>0)
        {
            add=step_val;
        }
    }
    void increment()
    {
        count+=add;
    }

    int getCount()
    {
        return count;
    }

    void resetCount()
    {
        count=0;
    }

    //c1 =c2+c3
    Counter operator +(Counter c3)
    {
        return Counter((count+c3.count),min(add,c3.add));
    }

    Counter operator +(int var)
    {
        return Counter((count+var),count);
    }

    friend Counter operator +(int var,Counter c1 );


    Counter operator ++()
    {
        return Counter(++count,add);
    }



    Counter operator ++(int)
    {
        return Counter(count++,add);
    }

    void operator +=(Counter c1)
    {
        count+=c1.count;

    }

};


Counter operator +(int var,Counter c1 )
{
    return Counter(var+c1.count,c1.count);
}


int main()
{

   Counter c1,c2(3,3),c3;

   //increment set and printing c1
   c1.setIncrementStep(4);
   c1.increment();
   cout<<c1.getCount()<<endl;


   //increment set and printing c2


   c2.increment();
   cout<<c2.getCount()<<endl;


   //assigning c1 and c2 into c3

   c3=c1+c2;
   cout<<c3.getCount()<<endl;

   //c1+=c2

   c1+=c2;
   cout<<c1.getCount()<<endl;

   //c2=c1++

   c2=c1++;
   cout<<c2.getCount()<<endl;

   //c2=++c1;
   c2=++c1;
   cout<<c2.getCount()<<endl;

}
