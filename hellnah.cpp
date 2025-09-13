#include <iostream>
using namespace std;

void ArrayGotReverse(int *Array, int ArraySize)
{
    int reversedArr[ArraySize];
    int reversedSize = 0;

    for (int i = ArraySize - 1; i >= 0; i--)
    {
        reversedArr[reversedSize] = Array[i];
        reversedSize++;
    }

    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = reversedArr[i];
    }
}

int main()
{
    const int Ganjil = 7;
    int arr[Ganjil] = {3, 6, 9, 12, 15, 18, 21};

    cout << "Array Sebelum Dibalik: ";
    for (int i = 0; i < Ganjil; i++)
        cout << arr[i] << " ";
    cout << endl;

    ArrayGotReverse(arr, Ganjil);

    cout << "Array Sesudah Dibalik: ";
    for (int i = 0; i < Ganjil; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
