#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool anw (string a, string b)
{
    if (a == b) return true;
    if (a.size()%2 != 0) return false;
    int n = a.size()/2;
    bool f1 = anw(a.substr(0,n), b.substr(n)) && anw(a.substr(n), b.substr(0,n));
    if (f1) return true;
    bool f2 = anw(a.substr(0,n), b.substr(0,n)) && anw(a.substr(n), b.substr(n));
    return f2;
}

int main()
{
    string a,b;
    cin >> a >> b;
    cout << (anw(a,b) ? "YES" : "NO") << endl;
}
