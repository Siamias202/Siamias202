#include<bits/stdc++.h>
using namespace std;
enum Furniture_type {bed, diningTable,sofa};
const int MAX = 100;
class Furniture
{
protected:
    int regularPrice,discountPrice;
    string material;
    static int n;
    static Furniture* arr[];
public:
    Furniture()
    {
        regularPrice=0;
        discountPrice=0;
        material="Nothing";
    }
    Furniture(int a, int b, string c)
    {
        regularPrice=a;
        discountPrice=b;
        material=c;
    }
    virtual void getdata()
    {
        cin.ignore(10, '\n');
        cout<<"Enter Regular Price: ";
        cin>>regularPrice;
        cout<<"Enter Discount Price: ";
        cin>>discountPrice;
        cout<<"Enter Material Type: ";
        cin>>material;
    }
    virtual void putdata()
    {
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"Regular Price: "<<regularPrice<<"\nDiscount Price: "<<discountPrice<<"\nMaterial: "<<material;

    }
    virtual Furniture_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();

};
int Furniture::n;
Furniture* Furniture::arr[MAX];
class Bed : public Furniture
{
private:
    string bedSize;
public:
    Bed()
    {
        bedSize="Nothing";
    }
    Bed(int a, int b, string c, string d)
    {
        regularPrice=a;
        discountPrice=b;
        material=c;
        bedSize=d;
    }
    void getdata()
    {
        Furniture::getdata();
        cout<<"Enter Bed size : ";
        cin>>bedSize;
    }
    void putdata()
    {
        Furniture::putdata();
        cout<<"\nBed Size : "<<bedSize<<endl;
        cout<<"##########################################################################"<<endl;

    }
};
class Sofa : public Furniture
{
private:
    int seatNumber;
public:
    Sofa()
    {
        seatNumber=0;
    }
    Sofa(int a, int b, string c, int d)
    {
        regularPrice=a;
        discountPrice=b;
        material=c;
        seatNumber=d;
    }
    void getdata()
    {
        Furniture::getdata();
        cout<<"Enter Seat Number : ";
        cin>>seatNumber;
    }
    void putdata()
    {
        Furniture::putdata();
        cout<<"\nSeat Number : "<<seatNumber<<endl;
        cout<<"##########################################################################"<<endl;

    }

};
class DiningTable : public Furniture
{
private:
    int chairCount;
public:
    DiningTable()
    {
        chairCount=0;
    }
    DiningTable(int a, int b, string c, int d)
    {
        regularPrice=a;
        discountPrice=b;
        material=c;
        chairCount=d;
    }
    void getdata()
    {
        Furniture::getdata();
        cout<<"Enter Chair Count : ";
        cin>>chairCount;
    }
    void putdata()
    {
        Furniture::putdata();
        cout<<"\nChair Count : "<<chairCount<<endl;
        cout<<"##########################################################################"<<endl;

    }

};
void Furniture::write()
{
    int size;
    cout << "Writing " << n << " furnitures.\n";
    ofstream ouf;
    Furniture_type etype;
    ouf.open("furniture.txt", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        etype = arr[j]->get_type();
        ouf.write( (char*)&etype, sizeof(etype) );
        switch(etype)
        {
        case bed:
            size=sizeof(Bed);
            break;
        case diningTable:
            size=sizeof(DiningTable);
            break;
        case sofa:
            size=sizeof(Sofa);
            break;
        }
        ouf.write( (char*)(arr[j]), size );
        if(!ouf)
        {
            cout << "\nCan’t write to file\n";
            return;
        }
    }
}
void Furniture::read()
{
    int size;
    Furniture_type etype;
    ifstream inf;
    inf.open("furniture.txt",ios::binary);
    if(!inf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        inf.read( (char*)&etype, sizeof(etype) );
        if( inf.eof() )
            break;
        if(!inf)
        {
            cout << "\nCan’t read type from file\n";
            return;
        }
        switch(etype)
        {
        case bed:
            arr[n] = new Bed;
            size=sizeof(Bed);
            break;
        case diningTable:
            arr[n] = new DiningTable;
            size=sizeof(DiningTable);
            break;
        case sofa:
            arr[n] = new Sofa;
            size=sizeof(Sofa);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        }
        inf.read( (char*)arr[n], size );
        if(!inf)
        {
            cout << "\nCan’t read data from file\n";
            return;
        }
        n++;
    }
    cout << "Reading " << n << " furnitures\n";
}
void Furniture::add()
{
    char ch;
    cout << "'b' to add a bed"
         "\n's' to add a sofa"
         "\n'd' to add a dining table"
         "\nEnter selection: ";
    cin >> ch;
    switch(ch)
    {
    case 'b':
        arr[n] = new Bed;
        break;
    case 'd':
        arr[n] = new DiningTable;
        break;
    case 's':
        arr[n] = new Sofa;
        break;
    default:
        cout << "\nUnknown Furniture type\n";
        return;
    }
    arr[n++]->getdata();
}
void Furniture::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1); //display number
        switch( arr[j]->get_type() ) //display type
        {
        case bed:
            cout << ". Type: bed\n";
            break;
        case diningTable:
            cout << ". Type: dining table\n";
            break;
        case sofa:
            cout << ". Type: sofa\n";
            break;
        default:
            cout << ". Unknown type\n";
        }
        arr[j]->putdata();
        cout << endl;
    }
}
Furniture_type Furniture::get_type()
{
    if( typeid(*this) == typeid(Bed) )
        return bed;
    else if( typeid(*this)==typeid(DiningTable) )
        return diningTable;
    else if( typeid(*this)==typeid(Sofa) )
        return sofa;
    else
    {
        cerr << "\nBad furniture type";
        exit(1);
    }
    //return _bed;
}
int main()
{
    while(1)
    {
        cout << "'a' -- add data for an furniture"
             "\n'd' -- display data for all furniture"
             "\n'w' -- write all furniture data to file"
             "\n'r' -- read all furniture data from file"
             "\n'x' -- exit"
             "\nEnter selection: ";
        char ch;
        cin >> ch;
        switch(ch)
        {
        case 'a':
            Furniture::add();
            break;
        case 'd':
            Furniture::display();
            break;
        case 'w':
            Furniture::write();
            break;
        case 'r':
            Furniture::read();
            break;
        case 'x':
            exit(0);
        default:
            cout << "\nUnknown command";
        }
    }
    return 0;
}
