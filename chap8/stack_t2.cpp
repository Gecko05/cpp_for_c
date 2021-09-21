// safe character stack
#include <stack>
#include <assert.h>

using namespace std;

class safe_char_stack : public stack<char> {
public:
    // test push and pop
    void push(char c)
    {
        assert(!full());
        stack<char>::push(c);
    }
    char pop()
    {
        assert(!empty());
        return (stack<char>::pop());
    }
};