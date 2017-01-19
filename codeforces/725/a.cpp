#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int N; cin >> N;
    string S; cin >> S;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        if (S[i] == '<')
            ++cnt;
        else break;
    for (int i = 0; i < N; ++i)
        if (S[N-i-1] == '>')
            ++cnt;
        else break;
    cout << cnt << '\n';
	return 0;
}

