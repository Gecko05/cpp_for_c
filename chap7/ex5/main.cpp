#include <iostream>
using namespace std;

template<class TYPE>
void rotate(TYPE a[], int sz)
{
    TYPE r = a[sz-1];
    for (int i = sz-1; i > 0; i--)
    {
        a[i] = a[i-1]; 
    }
    a[0] = r;
}

int main()
{
    float arr[4] = {0.1, 0.2, 0.3, 0.4};
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    rotate(arr, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
}