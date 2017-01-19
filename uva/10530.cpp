#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        bool ans = false;
        int lo = 1, hi = 10;
        while (true) {
            int x; string s; 
            cin >> x;
            getline(cin, s);
            getline(cin, s);
            if (s == "too high") {
                if (lo <= x && x <= hi)
                    hi = x-1;
                else if (x < lo)
                    ans = true;
            }
            else if (s == "too low") {
                if (lo <= x && x <= hi)
                    lo = x+1;
                else if (hi < x)
                    ans = true;
            }
            else if (s == "right on") {
                if (x < lo || hi < x)
                    ans = true;
                break;
            }
            if (lo > hi)
                ans = true;
        }
        cout << "Stan " << (ans ? "is dishonest" : "may be honest") << '\n';
        cin >> ws;
        if (cin.peek() == '0')
            break;
    }
    return 0;
}

