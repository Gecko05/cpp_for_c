// parametrized safe stack

template <class TYPE>
class safe_stack : public stack<TYPE>{
    public:
    void push(TYPE c)
    {
        assert(!full());
        stack<TYPE>::push(c);
    }
    TYPE pop()
    {
        assert(!empty());
        return (stack<TYPE>::pop());
    }
}