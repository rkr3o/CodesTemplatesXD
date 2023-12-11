#include<bits/stdc++.h>
using namespace std;

class Vehicle {
    string company , color , model;
    int price ;
public:
    Vehicle(string company , string color  , string model , int price)
    {

    }
    void getDetails()
    {
        cout << company << " " << color << " " << model << " " << price << endl;
    }
};

class Cars :: public Vehicle {

    string Carname;
    Cars(company, color, model, price, name) : Vehicle(company, color, model, price)
    {
        Carname = name;
    }
    getDetails();
    cout << Carname << endl;
};
class Ships :: public Vehicle {

    string Shipname;
    Cars(company, color, model, price, name) : Vehicle(company, color, model, price)
    {
        Shipname = name;
    }
    getDetails();
    cout << Shipname << endl;
};

int main()
{

}