bool strneq(const char* s1, const char* s2, int){
    while ( *s1 != 0 && *s2 != 0 && n > 0){
        if (*s1++ != *s2++){
            return false;
        }
        n--;
    }
    return (*s1 == *s2);
}