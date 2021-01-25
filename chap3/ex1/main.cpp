#include <iostream>

bool strneq(const char* s1, const char* s2, int n){
    while ( *s1 != 0 && *s2 != 0 && n-- > 0){
        if (*s1++ != *s2++){
            return false;
        }
        //n--;
    }
    return (*s1 == *s2);
}

int main(){
    char hola[] = "this is my new string";
    char hola1[] = "this is1my new string";
    char hola2[] = "this is";
    if (strneq(hola, hola1, 7)){
        std::cout << "Pass0" << std::endl;
    }
    if (strneq(hola1, hola2, 8)){
        std::cout << "Fail1" << std::endl;
    }
}