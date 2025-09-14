#include <iostream>
using namespace std;

struct mahasiswa
{
    int nim;
    float ipk;
    string nama;
    string alamat;
};
mahasiswa dataMahasiswa;

int main()
{
    // dataMahasiswa.nama = "Dimas";
    // cout << "Nama: " << dataMahasiswa.nama << endl;

    mahasiswa data[4];

    data[0].nama = "Nabil";
    data[0].nama = "Dante";
    data->nama = "ucup";

    cout << data[0].nama << endl;
    cout << data[1].nama << endl;

    return 0;
}