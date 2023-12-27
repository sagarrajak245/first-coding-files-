#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int x = 5;
    int y = 6;

    swap(&x, &y);
    cout << "the swapped values are: " << x << ", " << y;

    return 0;
}
