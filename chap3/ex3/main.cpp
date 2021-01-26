// recursive string length
#include <iostream>

size_t strlen(const char *s, size_t len = 0){
    if (*s == '\0'){
        return len;
    }
    return strlen(++s, len) + 1;
}

int main(){
    std::cout << strlen("Hola mundo") << std::endl;
}