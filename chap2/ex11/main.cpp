#include <iostream>
using namespace std;

void temp_conv(string temp)
{
    int len = temp.length();
    if (len < 2){
        return;
    }
    if (temp[len-1] == 'F'){
        int deg = stoi(temp.substr(0, len-1));
        deg = (deg - 32)/1.8;
        cout << deg << 'C' << endl;
    }
    else if (temp[len-1] == 'C'){
        int deg = stoi(temp.substr(0, len-1));
        deg = (deg * 1.8) + 32;
        cout << deg << 'F' << endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    temp_conv("42C");
    temp_conv("106F");
}