#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    int account_number;
    string account_holder;
    string account_type;
    int current_balance;
    int minimum_balance;
public:
    BankAccount(int acn,string ach,string act,int cb,int mb)
    {
        account_number=acn;
        account_holder=ach;
        account_type=act;
        current_balance=cb;
        minimum_balance=mb;
    }

    void deposit(int add)
    {
        current_balance+=add;
    }

    void withdrawal(int with)
    {
        if(current_balance==minimum_balance)
        {
            cout<<"Invalid Withdrawal"<<endl;
        }
        else
        {
            current_balance-=with;
        }
    }

    void giveInterest()
    {
        double d=current_balance*(3/100)*1.0;
        current_balance+=d;
    }
    void giveInterest(int j)
    {
        double d=current_balance*(j/100)*1.0;
        current_balance+=j;
    }

    void showBalance()
    {
        cout<<"Current Balance is : "<<current_balance<<endl;
    }
    void show()
    {
        cout<<"Account Number is: "<<account_number<<endl;
        cout<<"Account Holder is: "<<account_holder<<endl;
        cout<<"Account Type is: "<<account_type<<endl;
        cout<<"Current Balance is: "<<current_balance<<endl;
        cout<<"Minimum Balance is: "<<minimum_balance<<endl;
    }
    ~BankAccount()
    {
        cout<<account_holder<<" with account no "<<account_number<<" is destroyed with a balance BDT "<<current_balance<<endl;
    }


};

int main()
{
    BankAccount ob1(1234,"Siam","Savings",60000,10000);
    ob1.showBalance();
    ob1.deposit(15000);
    ob1.showBalance();
    ob1.withdrawal(20000);
    ob1.showBalance();


}
