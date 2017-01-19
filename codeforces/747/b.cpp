#include <bits/stdc++.h>
using namespace std;

int n, a[256], m, k = 0;
string s;
vector<char> v = {'A', 'C', 'G', 'T'};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> s;
    if (n % 4 != 0) {
        cout << "===\n";
        return 0;
    }
    for (char c : s)
        a[c]++;
    m = max(max(a['A'], a['C']), max(a['G'], a['T']));
    for (char c : v)
        k += m - a[c];
    if (k <= a['?'] && (a['?'] - k) % 4 == 0) {
        m += (a['?'] - k) / 4;
        for (int i = 0; i < n; ++i)
            if (s[i] == '?')
                for (char c : v)
                    if (a[c] < m) {
                        s[i] = c;
                        a[c]++;
                        break;
                    }
        cout << s << '\n';
    }
    else cout << "===\n";
	return 0;
}

