#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
class Medicine
{
private:
    string name,genericName;
    double discountPercent,unitPrice;
public:
    void assignName(string name,string genericName)
    {
        this->name=name;
        this->genericName=genericName;
    }

    void assignPrice(double price)
    {
        if(price<0)
        {
            unitPrice=0;
        }
        else
        {
            unitPrice=price;
        }
    }

    void setDiscountPercent(double percent)
    {
        if(percent<0 || percent>45)
        {
            discountPercent=5;
        }
        else
        {
            discountPercent=percent;
        }
    }

    double getSellingPrice(int nos)
    {
        double res=unitPrice-unitPrice*((discountPercent/100)*1.00);
        return nos*res;
    }

    void display()
    {
        cout<<name<<"("<<genericName<<")"<<"has a unit price BDT "<<unitPrice<<" .Current discount "<<discountPercent<<"."<<endl;
    }
};
int main()
{
   boost;
   Medicine m1;
   m1.assignName("Ace","Paracetamol");
   m1.assignPrice(0.5);
   m1.setDiscountPercent(15);
   cout<<m1.getSellingPrice(10)<<endl;
   m1.display();
}
