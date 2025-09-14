#include <iostream>
using namespace std;

int main()
{
    int angka[2] = {10, 20};
    cout << angka[0] << endl;

    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    cout << arr2[1][1] << endl;

    int arr3[2][3][3] = {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}},
        {{10, 20, 30},
         {40, 50, 60},
         {70, 80, 90}}};

    cout << arr3[1][1][2] << endl;

    return 0;
}