#include <iostream>
using namespace std;

void changenumber(int *ptr)
{
    cout << "Masukkan  nilai: ";
    cin >> *ptr;
    cout << endl;
};

void changenumber2(int &ptr)
{
    cout << "Masukkan  nilai: ";
    cin >> ptr;
    cout << endl;
};

int main()
{

    int number = 10;
    changenumber(&number);
    cout << number << endl;
    changenumber2(number);
    cout << number << endl;
    
    

    //cout << "Alamat number : " << &number << endl;
    //cout << "Nilai ptrc: " << ptr << endl;
    //cout << "Alamat ptr : " << &ptr << endl;

    //cout << "Sebelum" << number << endl;
    //*ptr = 30;
    //cout << "Sesudah" << number << endl;

    return 0;
}