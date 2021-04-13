#include "slist.h"

using namespace std;

struct slistelem {
    char data;
    slistelem* next;
};

class slist {               // a singly linked list
    public:
        slist() : h(0) { }  // 0 denontes empty slist
        slist(const char* c);
        ~slist() { release(); }
        void prepend(char c); // adds to front of slist
        void del();
        slistelem* first() const { return h; }
        void print() const;
        void release();
        int length();
        int count_c(char c);
    private:
        slistelem* h; // head of slist
};


slist::slist(const char* c) : h(0)
{
    while (c != 0)
    {
        prepend(*c);
        c++;
    }
}

void slist::prepend(char c)
{
    slistelem* temp = new slistelem;
    assert(temp != 0);
    temp -> next = h;
    temp -> data = c;
    h = temp;
}

void slist::del()
{
    slistelem* temp = h;

    h = h->next; // presumes a nonempty slist
    delete temp;
}

void slist::print() const
{
    slistelem* temp = h;

    while (temp != 0)
    {
        cout << temp -> data << " -> ";
        temp = temp ->next;
    }
    cout << "\n###" << endl;
}

void slist::release()
{
    while (h != 0)
        del();
}

int slist::length()
{
    slistelem* temp = h;
    int len = 0;
    while (temp != 0)
    {
        len += 1;
        temp = temp->next;
    }
    return len;
}

int slist::count_c(char c)
{
    int cnt = 0;
    slistelem* temp = h;
    while (temp != 0)
    {
        if (temp->data == c)
        {
            cnt++;
        }
        temp = temp->next;
    }
    return cnt;
}