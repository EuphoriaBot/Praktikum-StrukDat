#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    double ipk;
};

int main()
{
    Mahasiswa mhs[5] = {
        {"DimasAsli", "057", 1.2},
        {"DimasDua", "0572", 2.8},
        {"DimasTiga", "0573", 1.9},
        {"DimasEmpat", "0574", 3.9},
        {"DimasLima", "0575", 2.2}};

    int IndexTinggi = 0;
    for (int i = 1; i < 5; i++)
    {
        if (mhs[i].ipk > mhs[IndexTinggi].ipk)
        {
            IndexTinggi = i;
        }
    }

    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[IndexTinggi].nama << endl;
    cout << "NIM  : " << mhs[IndexTinggi].nim << endl;
    cout << "IPK  : " << mhs[IndexTinggi].ipk << endl;

    return 0;
}
