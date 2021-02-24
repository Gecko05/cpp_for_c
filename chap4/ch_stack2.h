class ch_stack {
    public:
    // the public interface for the ch_stack
        explicit ch_stack(int size): max_len(size), top(EMPTY)
        {
            assert(size > 0);
            s = new char[size];
            assert(s != 0);
        }
        void reset() { top = EMPTY; }
        void push(char c) { s[++top] = c; }
        char pop() { return s[top--]; }
        char top_of() const { return s[top]; }
        bool empty() const { return (top == EMPTY); }
        bool full() const { return (top == max_len - 1); }
    private:
        enum { EMPTY = -1 };
        char* s; // changed from s[max_len]
        int max_len;
        int top;
};