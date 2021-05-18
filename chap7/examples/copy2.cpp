template<class T1, class T2>
void copy(T1 a[], T2 b[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = b[i];
    }
}