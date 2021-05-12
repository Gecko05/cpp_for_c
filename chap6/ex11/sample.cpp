#include <iostream>

using namespace std;

class husta
{
    public:
        husta();
        husta(const int d[], int n);
        ~husta();
    private:
        int *p;
        int sz;
};

husta::husta()
{
    p = new int[1];
    sz = 0;
}

husta::husta(const int d[], int n)
{
    p = new int[n];
    sz = n;
    for (int i = 0; i < n; i++)
    {
        p[i] = d[i];
    }
}

husta::~husta()
{
    delete[] p;
}

int main()
{
    const int arr[3] = {2,3,4};
    husta myHusta(arr, 3);
}