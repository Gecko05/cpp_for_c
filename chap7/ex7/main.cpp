#include <iostream>
#include "vect_it.h"

int arr[3] = {2,1,3};
int arr2[5] = {5,6,7,8};

int main()
{
    vector<int> my_vec(arr, 3);
    vector<int> my_vec2(arr2, 4);
    my_vec.print();
    my_vec2.print();
    my_vec = my_vec2;
    my_vec.print();
}
