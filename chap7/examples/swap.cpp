// generic swap

#include <string>

template <class T>
void swap(T& x, T& y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}

void swap(char* s1, char* s2)
{
    int max_len;
    
    max_len = (strlen(s1) >= strlen(s2)) ?
               strlen(s1) : strlen(s2);
    char* temp = new char[max_len + 1];

    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
    delete []temp;
}