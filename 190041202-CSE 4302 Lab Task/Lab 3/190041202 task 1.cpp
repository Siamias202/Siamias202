#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
class Counter
{
private:
    int count,a;
public:
    Counter():count(0),a(0)
    {

    }
    void setIncrementStep(int step_val)
    {
        a=step_val;
    }
    int getCount()
    {
        return count;
    }
    void resetCount()
    {
        count=0;
    }
    void increment()
    {
        count+=a;
    }

};

int main()
{
    boost;
    Counter c1;
    c1.setIncrementStep(10);
    c1.increment();
    cout<<c1.getCount()<<endl;
    c1.resetCount();
    cout<<c1.getCount()<<endl;


}
