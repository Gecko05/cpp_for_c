// Simple fault tolerance using _new_handler

void heap_exhausted() // user-defined error handling
{
    cerr << "HEAP EXHAUSTED" << endl;
    exit(1);
}

int main()
{
    set_new_handler(heap_exhausted);
    // memory exhaustion is like heap_exhausted()
}