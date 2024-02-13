#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct Employee
{
private:
    int emp_id;
    string emp_name;
    string emp_quli;
    long long int number;

public:
    void setData() 
    {
        cout << "Enter employee id: ";
        cin >> emp_id;
        cout << "Enter employee name: ";
        cin.ignore(); // To handle the newline character left in the buffer
        getline(cin, emp_name);
        cout << "Enter employee qualification: ";
        getline(cin, emp_quli);
        cout << "Enter employee contact number: ";
        cin >> number;
    }

    void displayData()
    {   
        for(int i = 0; i < 60; i++)
            cout << "*";
        cout << left << setw(31) << "\nEmployee id" << ":" << emp_id << endl;
        cout << left << setw(30) << "Employee name " << ":" << emp_name << endl;
        cout << left << setw(30) << "Employee qualification " << ":" << emp_quli << endl;
        cout << left << setw(30) << "Employee contact number " << ":" << number << endl;
    }

    int getEmployeeId() const {
        return emp_id;
    }
};

int main()
{
    int n, eid;
    cout << "\nEnter the number of employees: ";
    cin >> n;

    Employee *e = new Employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter data for employee " << i + 1 << ":\n";
        e[i].setData();
    }

    char ch;
    do
    {
        for (int i = 0; i < 60; i++)
            cout << "*";
        cout << "\nEnter employee id for information: ";
        cin >> eid;
        for (int i = 0; i < 60; i++)
            cout << "*";
        int j;
        for (j = 0; j < n; j++)
        {
            if (eid == e[j].getEmployeeId())
            {
                cout << "\nData for employee " << j + 1 << ":\n";
                e[j].displayData();
                break;
            }
        }

        if (j == n)
        {
            cout << "\nEmployee id is not valid." << endl;
        } 
        for (int i = 0; i < 60; i++)
            cout << "*";
        cout << "\nIf you want other information press y and for exit press n: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    delete[] e;

    return 0;
}
