struct sister;

struct brother{
    char name[20];
    int age;
    struct sister sib;
} a;

struct sister {
    char name[20];
    int age;
    brother sib;
} b;
