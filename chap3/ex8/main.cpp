// file A.c

static int foo(int i){
    return (i * 3);
}

int goo(int i )
{
    return (i * foo(i));
}

// file B.c

int foo(int i)
{
    return (i * 5);
}

int goo(int i); // imported from file A.c

int main(){
    cout << "foo(5) = " << foo(5) << endl;
    cout << "goo(5) = " << goo(5) << endl;
}

// It should print:
// foo(5) = 25 since foo from file A.c is static
// goo(5) = 45 since file A.c will use its static def