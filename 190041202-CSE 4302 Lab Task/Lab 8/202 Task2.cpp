#include<bits/stdc++.h>
using namespace std;


class Staff
{
protected:
    int code;
    string name;
public:
    void set_code(int c)
    {
        code=c;
    }
    void set_name(string a)
    {
        name=a;
    }
};

class Teacher:public Staff
{
private:
    string Subject;
    string Publication;
public:
    void set_subject(string s)
    {
        Subject=s;
    }
    void set_publication(string p)
    {
        Publication=p;
    }
    void who_am_I()
    {
        cout<<"Name   code   Subject                Publication"<<endl;
        cout<<Staff::name<<"  "<<Staff::code<<"    "<<Subject<<"   "<<Publication<<endl;
    }
};

class officer:public Staff
{
private:
    string grade;
public:
    void set_grade(string g)
    {
        grade=g;
    }
    void who_am_I()
    {
        cout<<"Name         code  Category"<<endl;
        cout<<Staff::name<<"    "<<Staff::code<<"   "<<grade<<endl;
    }
};

class typist:public Staff
{
protected:
    double speed;
public:
    void set_speed(double s)
    {
        speed=s;
    }

};

class regular:public typist
{

public:
    void who_am_I()
    {
        cout<<"Name         code   speed"<<endl;
        cout<<Staff::name<<"  "<<Staff::code<<"    "<<speed<<endl;
    }
};

class causal:public typist
{
private:
    int wage;
public:
    void set_wage(int w)
    {
        wage=w;
    }
    void who_am_I()
    {
        cout<<"Name           code    speed   wage"<<endl;
        cout<<Staff::name<<"  "<<Staff::code<<"     "<<speed<<"    "<<wage<<endl;
    }
};


int main()
{
    Teacher t1;
    t1.set_code(420);
    t1.set_name("Ataur");
    t1.set_publication("Tata McGraw Hill");
    t1.set_subject("programming with c++");
    t1.who_am_I();


    officer o1;
    o1.set_code(222);
    o1.set_grade("First Class");
    o1.set_name("Md.Rashed");
    o1.who_am_I();


    regular r1;
    r1.set_code(333);
    r1.set_name("Robiul Awal");
    r1.set_speed(85.5);
    r1.who_am_I();

    causal c1;
    c1.set_code(333);
    c1.set_name("Kawser Ahamed");
    c1.set_wage(10000);
    c1.set_speed(78.90002);
    c1.who_am_I();

}
