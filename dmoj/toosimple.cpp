#include <bits/stdc++.h>
using namespace std;

void pbits(string const& s) { 
    for(size_t i=0; i<s.size(); i++) 
        cout << bitset<CHAR_BIT>(s[i]) << " "; 
} 

int main() {
    pbits("\x80\x70"); 
    cout << "\xff\n";
}

