#include "student2.h"

int main()
{
    student s("Mae Pohl", 100, 3.425, student::fresh);
    student *ps = &s;
    grad_student gs("Morris Pohl", 200, 3.2564,
        student::grad, grad_student::ta, "Pharmacy",
        "Retail Pharmacies");
    grad_student *pgs;
    ps->print();    //student::print
    ps = pgs = &gs;
    pgs->print();   //grad_student::print
    ps->print();    //student::print
    ps->setData();
    ps->print();
    pgs->setData();
    pgs->print();
}