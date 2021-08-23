#include<bits/stdc++.h>
using namespace std;

class phone
{
protected:
    string name;
public:
    virtual void type()=0;
    virtual void getter(string s)=0;
};

class andriod:public phone
{
public:
    void type()
    {
        cout<<name<<" is an andriod phone"<<endl;
    }

    void getter(string s)
    {
        name=s;
    }


};


class ios:public phone
{
public:
    void type()
    {
        cout<<name<<" is an ios phone"<<endl;
    }

    void getter(string s)
    {
        name=s;
    }

};

int main()
{
    phone *p=new andriod();
    string s;
    cin>>s;
    p->getter(s);
    p->type();
}
