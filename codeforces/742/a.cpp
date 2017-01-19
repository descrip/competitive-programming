#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "1\n";
        return 0;
    }
    vector<int> v = {8, 4};
    while (v.back() != v[0])
        v.push_back((v.back() * 1378) % 10);
    v.pop_back();
    cout << v[((n-1) % v.size())] << '\n';
	return 0;
}

