template<class TYPE>
void copy(TYPE a[], TYPE b[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = b[i];
    }
}