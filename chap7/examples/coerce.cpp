
template <class T1, class T2>
bool coerce(T1& x, T2 y)
{
    if (sizeof(x) < sizeof(y))
    {
        return false;
    }
    x = static_cast<T1>(y);
    return true;
}