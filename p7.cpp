#include<iostream>
using namespace std;

class COMPLEX {
private:
    float r;
    float i;
public:
    void getdata() {
        cout << "Real part :" << endl;
        cin >> r;
        cout << "Imaginary part :" << endl;
        cin >> i;
    }

    COMPLEX operator +(COMPLEX temp1) {
        COMPLEX temp2;
        temp2.r = r + temp1.r;
        temp2.i = i + temp1.i;
        return temp2;
    }

    COMPLEX operator -(COMPLEX temp1) {
        COMPLEX temp2;
        temp2.r = r - temp1.r;
        temp2.i = i - temp1.i;
        return temp2;
    }

    COMPLEX operator *(COMPLEX temp1) {
        COMPLEX temp2;
        temp2.r = (r * temp1.r) - (i * temp1.i);
        temp2.i = (r * temp1.r) + (i * temp1.i);
        return temp2;
    }

    COMPLEX operator /(COMPLEX temp1) {
        COMPLEX temp2;
        temp2.r = ((r * temp1.r) + (i * temp1.i)) / (i*i + temp1.i*temp1.i);
        temp2.i = ((i * temp1.r) - (r * temp1.i)) / (i*i + temp1.i*temp1.i);
        return temp2;
    }
    COMPLEX operator ! ()
    {
        COMPLEX temp;
        temp.r = -r;
        temp.i = -i;
        return temp;
    }
    void putdata()
    {
        cout<< r << "+"<<"("<< i <<")i"<<endl; 
    }
};

int main() {
    COMPLEX c1, c2, c3;
    c1.getdata();
    c2.getdata();
    char ch;
    cout << "Choose operator :" << endl;
    cout << "(+) Addition" << endl;
    cout << "(-) Subtraction" << endl;
    cout << "(*) Multiplication" << endl;
    cout << "(/) Division" << endl;
    cout << "(!) Negation" << endl;
    cin >> ch;
    switch (ch) {
    case '+':
        c3 = c1 + c2;
        c3.putdata();
        break;
    case '-':
        c3 = c1 - c2;
        c3.putdata();
        break;
    case '*':
        c3 = c1 * c2;
        c3.putdata();
        break;
    case '/':
        c3 = c1 / c2;
        c3.putdata();
        break;
    case '!':
        c3=!c1;
        cout<<"For first complex number :"<<endl;
        c3.putdata();
        c3=!c2;
        cout<<"For second complex number :"<<endl;
        c3.putdata();
    default:
        cout << "Invalid operator!!!" << endl;
        break;
    }
    return 0;
}
