// Use of the find function

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string words[5] = { "my", "hop", "mopp", "hope", "cope"};
    string* where;

    where = find(words, words + 5, "hop");
    cout << *++where << endl;       //mop
    sort(words, words + 5);
    where = find(words, words + 5, "hop");
    cout << *++where << endl;       // hope
}