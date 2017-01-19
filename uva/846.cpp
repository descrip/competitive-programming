#include <bits/stdc++.h>
using namespace std;

int T, X, Y;
vector<long long> dist = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int pos = 1;
    while (dist.back() < (1LL<<31)) {
        dist.push_back(dist.back() + pos/2 + (pos%2==1));
        ++pos;
    }
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> X >> Y;
        long long d = Y - X;
        cout << lower_bound(dist.begin(), dist.end(), d) - dist.begin() << '\n';
    }
	return 0;
}

