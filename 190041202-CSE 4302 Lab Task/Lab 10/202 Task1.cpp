/*
 Virtual Function

*/

#include<bits/stdc++.h>
using namespace std;


class Animal
{
private:
    string s="Animal class";
public:
    void display()
    {
        cout<<"This is "<<s<<endl;
    }

    virtual void walk()
    {
        cout<<"Animal walking"<<endl;
    }

    virtual  void sound()
    {
        cout<<"Animal sound"<<endl;
    }

};

class Dog:public Animal
{
private:
    string s="Dog Class";
public:
    void walk()
    {
        cout<<"Dog walk"<<endl;
    }
    void sound()
    {
        cout<<"Dog sound"<<endl;
    }
};

int main()
{
    Animal *a;
    Dog d;
    a=&d;
    a->sound();
    a->display();
}
