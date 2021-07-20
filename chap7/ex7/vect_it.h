// Template-based vector type
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class vector {
    public:
        typedef T* iterator;
        explicit vector(int n = 100); // create a size n array
        vector(const vector<T>& v);   // copy vector
        vector(const T a[], int n);   // copy and array
        void print();
        ~vector() { delete []p; }
        iterator begin() { return p; }
        iterator end(){ return p + size; }
        T& operator[](int i);         // range-checked element
        vector<T>& operator=(const vector<T>& v);
    private:
        T* p;                         // base pointer
        int size;                     // number of elements
};

template <class T>
vector<T>::vector(int n): size(n)
{
    assert(n > 0);
    p = new T[size];
    assert(p != 0);
}

template <class T>
vector<T>::vector(const T a[], int n)
{
    assert(n > 0);
    size = n;
    p = new T[size];
    assert(p != 0);
    for (int i = 0; i < size; ++i)
    {
        p[i] = a[i];
    }
}

template <class T>
vector<T>::vector(const vector<T>& v)
{
    size = v.size;
    p = new T[size];
    assert(p != 0);
    for (int i = 0; i < size; ++i)
    {
        p[i] = v.p[i];
    }
}

template <class T>
T& vector<T>::operator[](int i)
{
    assert (i >= 0 && i < size);
    return p[i];
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& v)
{
    assert(p != v.p);
    int size_diff = size - v.size;
    delete []p;
    p = new T[size];
    assert(p != 0);
    size = v.size;
    for (int i = 0; i < size; ++i)
    {
        p[i] = v.p[i];
    }
    return *this;
}

template<class T>
void vector<T>::print()
{
    for (iterator i = begin(); i < end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}