#include "dbl_vect.h"

int main(int argc, char *argv[])
{
    dbl_vect mv1(4);
    dbl_vect mv2(3);
    dbl_vect res(1);

    mv1.element(0) = 2;
    mv1.element(1) = 0;
    mv1.element(2) = 0;
    mv1.element(3) = 4;
    mv2.element(0) = 5;
    mv2.element(1) = 0;
    mv2.element(2) = 0;
    res.add(mv1,mv2);
    res.print();

    return 0;
}