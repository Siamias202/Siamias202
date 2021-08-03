#include<bits/stdc++.h>
using namespace std;


class Seat
{
private:
    string comfortability;
    string presence_of_seat_warmer;
public:
    void set_seat_info()
    {
        cout<<"Enter info for Comfortability: ";
        cin>>comfortability;
        cout<<endl;

        cout<<"Enter info for Presence of seat of warmer:";
        cin>>presence_of_seat_warmer;
        cout<<endl;
    }
    void get_seat_info()
    {
        cout<<"Comfortability: "<<comfortability<<endl;
        cout<<"Presence of seat warmer: "<<presence_of_seat_warmer<<endl;
    }
};

class Wheel
{
private:
    double radius;
public:
    Wheel():radius(0)
    {

    }
    void set_radius()
    {
        cout<<"Enter radius:"<<endl;
        cin>>radius;
    }
    void get_radius()
    {
        cout<<"Radius is:"<<radius<<endl;
    }
};

class Engine
{
private:
    double Maximum_Fuel_Consumption_Rate;
    double Maximum_Energy_Production_Rate;
    double Average_RPM;
public:
    Engine():Maximum_Fuel_Consumption_Rate(0),Maximum_Energy_Production_Rate(0),Average_RPM(0)
    {

    }
    void set_Engine_info()
    {
        cout<<"Enter Maximum Fuel Consumption Rate:";
        cin>>Maximum_Fuel_Consumption_Rate;
        cout<<endl;

        cout<<"Enter Maximum Energy Production Rate:";
        cin>>Maximum_Fuel_Consumption_Rate;
        cout<<endl;

        cout<<"Enter Average RPM :";
        cin>>Average_RPM;
        cout<<endl;

    }

    void get_Engine_info()
    {
        cout<<"Maximum Fuel Consumption Rate:"<<Maximum_Fuel_Consumption_Rate<<endl;
        cout<<"Maximum Energy Production Rate:"<<Maximum_Energy_Production_Rate<<endl;
        cout<<"Average RPM:"<<Average_RPM<<endl;
    }
};


class Door
{
private:
    string opening_mode;
public:
    void set_Info_opening_mode()
    {
        cout<<"Enter info for opening mode:";
        cin>>opening_mode;
        cout<<endl;
    }

    void get_info_opening_mode()
    {
        cout<<"Opening mode: "<<opening_mode<<endl;
    }
};

class Truck
{
private:
    double max_acceleration,fuel_capacity,Load_capacity;
    Seat s;
    Wheel w;
    Engine e;
    Door d;
public:
    Truck():max_acceleration(0),fuel_capacity(0),Load_capacity(0)
    {

    }

    void set_info_truck()
    {
        s.set_seat_info();
        w.set_radius();
        e.set_Engine_info();
        d.set_Info_opening_mode();
        cout<<"Enter Maximum Acceleration: ";
        cin>>max_acceleration;
        cout<<"Enter Fuel Capacity: ";
        cin>>fuel_capacity;
        cout<<"Load Capacity: ";
        cin>>Load_capacity;
    }

    void display()
    {
        s.get_seat_info();
        w.get_radius();
        e.get_Engine_info();
        d.get_info_opening_mode();
        cout<<"Maximum Acceleration:"<<max_acceleration<<endl;
        cout<<"Fuel Capacity:"<<fuel_capacity<<endl;
        cout<<"Load Capacity:"<<Load_capacity<<endl;
    }

};

int main()
{
    Truck t1;
    t1.set_info_truck();
    t1.display();

}
