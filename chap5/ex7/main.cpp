#include "string2.h"

// Sorting an array of strings
bool sless(my_string A, my_string B)
{
    if (A.strcmp(B) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void exch(my_string& A, my_string& B)
{
    my_string t(A);
    A.assign(B);
    B.assign(t); 
}

void compexch(my_string& A, my_string& B)
{
    if (sless(B, A) == true)
    {
        exch(A, B);
    }
}

void sort(my_string a[], int l, int r)
{
    int i;
    int j;
    for (i = l+1; i <=r; i++){
        for (j = i; j > l; j--){
            compexch(a[j-1], a[j]);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        a[i].print();
    }
}

int main(int argc, char *argv[])
{
    my_string toSort[4];
    toSort[0].assign("hola mama");
    toSort[1].assign("adios mama");
    toSort[2].assign("honeywell");
    toSort[3].assign("macarena");
    sort(toSort, 0, 3);
    return 0;
}