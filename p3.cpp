#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class cars
{
    string name, seating_capacity, fuelType, transmissionType;
    float showroom_price, mileage, tank_capacity;
    string airbags;
    int fuel, transmission;

public:
    void getdata();
    string getName() const;
    void display1();
    friend void display2(cars c[], int num);
    friend void display3(cars c[], int num);

private:
    string getFuelTypeString(int fuel);
    string getTransmissionTypeString(int transmission);
    static void displayHeader();
    void displayCommon();
};

void cars::getdata()
{
    cout << "Enter car name: ";
    cin >> name;
    cout << "Enter fuel type of car:\n for petrol press 1\n for diesel press 2\n for cng press 3\n for electric press 4" << endl;
    int fuel;
    cin >> fuel;
    if (fuel > 4)
    {
        cout<<"Invalid option please choose between 1 to 4."<<endl;
        cin>>fuel;
    }
    // Convert numeric fuel type to string
    fuelType = getFuelTypeString(fuel);

    cout << "Enter showroom price of car in lakhs: ";
    cin >> showroom_price;
    cout << "Enter mileage of car in km per liter: ";
    cin >> mileage;
    cout << "Enter transmission of car:\n for Manual press 1\n for AMT press 2" << endl;
    cin >> transmission;
    if (transmission > 2)
    {
        cout<<"Invalid option please choose between 1 and 2."<<endl;
        cin>>transmission;
    }
    // Convert numeric type to string
    transmissionType = getTransmissionTypeString(transmission);

    cout << "Enter tank capacity of car in liters: ";
    cin >> tank_capacity;
    cout << "Enter seating capacity of car: ";
    cin >> seating_capacity;
    cout << "Airbags available? Answer in yes or no " << endl;
    cin >> airbags;
}

string cars::getName() const
{
    return name;
}

void cars::display1()
{
    displayHeader();
    displayCommon();
}

void display2(cars c[], int num)
{
    int fuelOption;
    cout << "TATA Motors are available with the following fuel options:" << endl;
    cout << "Options:\n1. Petrol \n2. Diesel \n3. CNG \n4. Electric" << endl;
    cout << "Enter your option for fuel type: ";
    cin >> fuelOption;
    if (fuelOption > 4)
    {
        cout<<"Invalid option please choose between 1 to 4."<<endl;
        cin>>fuelOption;
    }
    cars::displayHeader();

    for (int i = 0; i < num; i++)
    {
        if (c[i].fuelType == c[i].getFuelTypeString(fuelOption))
        {
            c[i].displayCommon();
        }
    }
}

void display3(cars c[], int num)
{
    float choose_price;
    cout << "Enter your maximum affordable price in lakh." << endl;
    cin >> choose_price;

    cars::displayHeader();

    for (int i = 0; i < num; i++)
    {
        if (c[i].showroom_price <= choose_price)
        {
            c[i].displayCommon();
        }
    }
}

string cars::getFuelTypeString(int fuel)
{
    switch (fuel)
    {
    case 1:
        return "Petrol";
    case 2:
        return "Diesel";
    case 3:
        return "CNG";
    case 4:
        return "Electric";
    default:
        return "Unknown";
    }
}

string cars::getTransmissionTypeString(int transmission)
{
    switch (transmission)
    {
    case 1:
        return "Manual";
    case 2:
        return "AMT";
    default:
        return "Unknown";
    }
}

void cars::displayHeader()
{
    cout << left << setw(10) << "MODEL" << setw(10) << "FUEL" << setw(15) << "PRICE (Lakhs)" << setw(20) << "MILEAGE (km per l)" << setw(15) << "TRANSMISSION" << setw(25) << "TANK CAPACITY (Liters)" << setw(19) << "SEATING CAPACITY" << setw(10) << "AIRBAGS" << endl;
}

void cars::displayCommon()
{
    cout << left << setw(10) << name << setw(10) << fuelType << setw(15) << showroom_price << setw(20) << mileage << setw(15) << transmissionType << setw(25) << tank_capacity << setw(19) << seating_capacity << setw(10) << airbags << endl;
}


int main()
{
    int num, option, choose;
    cout << "Enter number of cars for data input: ";
    cin >> num;
    cars c[num];

    for (int i = 0; i < num; i++)
    {
        c[i].getdata();
    }
    system("CLS");
    char ch;
    cout << "Welcome to Tata Motors..." << endl;
    do
    {
        cout << "Get the car details as per your preference." << endl;
        cout << "Options:\n1. Model name\n2. Fuel type\n3. Price range\n";
        cin >> option;
        if (option > 3)
    {
        cout<<"Invalid option please choose between 1 to 3."<<endl;
        cin>>option;
    }
        if (option == 1)
        {
            cout << "List of cars" << endl;
            for (int i = 0; i < num; i++)
            {
                cout << i + 1 << "." << c[i].getName() << endl;
            }
            cout << "Choose car for details." << endl;
            cin >> choose;
            c[choose - 1].display1();
        }
        else if (option == 2)
        {
            display2(c, num);
        }
        else if (option == 3)
        {
            display3(c, num);
        }
        cout << "If you want more cars details press Y for Exist N." << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
