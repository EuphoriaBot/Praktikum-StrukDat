#include <iostream>
using namespace std;

int main()
{
    int Matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int Hasil = 0;
    for (int i = 0; i < 3; i++)
    {
        Hasil += Matriks[i][i];
        Hasil += Matriks[i][2 - i];
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jadi Jumlah Diagonal Utama Ditambah Diagonal Sekunder Adalah = " << Hasil << endl;

    return 0;
}
