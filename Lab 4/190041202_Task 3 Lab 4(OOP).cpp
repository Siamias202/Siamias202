#include<bits/stdc++.h>
using namespace std;

class Emp
{
private:
    string emp_name;
    int id;
    int age;
    double Salary;
    void get_status()
    {
        if(age<=25)
        {
            if(Salary<=20000)
            {
                cout<<"Low"<<endl;
            }
            else
            {
                cout<<"Moderate"<<endl;
            }
        }
        else
        {
            if(Salary<=21000)
            {
                cout<<"Low"<<endl;
            }
            else if(Salary>21000 && Salary<=60000)
            {
                cout<<"Moderate"<<endl;
            }
            else
            {
                cout<<"High"<<endl;
            }
        }
    }
public:
    void feedinfo(string name,int id,int age,double Salary)
    {
        emp_name=name;
        this->id=id;
        this->age=age;
        this->Salary=Salary;
    }

    void show()
    {
        cout<<"Employer Name is: "<<emp_name<<endl;
        cout<<"Id is: "<<id<<endl;
        cout<<"Age is: "<<age<<endl;
        cout<<"Salary is :"<<Salary<<endl;
        get_status();
    }

};

int main()
{
    Emp e1;
    e1.feedinfo("Siam",1,30,30000);
    e1.show();

}
