#include <iostream>
using namespace std;

void tukar(int **a, int **b)
{
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main()
{
    int x = 10, y = 20;
    int *px = &x;
    int *py = &y;

    cout << "Sebelum Di Tukar: X = " << x << ", Y = " << y << endl;

    tukar(&px, &py);

    cout << "Sesudah Di Tukar: X = " << x << ", Y = " << y << endl;

    return 0;
}
