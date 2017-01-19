#include <bits/stdc++.h>
using namespace std;

int C, N;
vector<int> coins;
bool dp[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> C >> N;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        coins.push_back(x);
    }
    dp[0] = 1;
    for (int i = 0; i < N; ++i)
        for (int i = 0; i <= 200000-coins[i]; ++i)
            dp[i+coins[i]] = 
	return 0;
}

