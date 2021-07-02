#include <iostream>
#include "vect_it.h"

int arr[3] = {2,1,3};

int main()
{
    vector<int> my_vec(arr, 3);
    my_vec.print();
}
