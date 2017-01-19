#include <bits/stdc++.h>
using namespace std;

int N, A[10005], M;
set<int> S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> N) {
        S.clear();
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            S.insert(A[i]);
        }
        sort(A, A+N);
        cin >> M;
        pair<int, int> ans = {0, 0xfffffff};
        for (int i = 0; i < N; ++i)
            if (S.count(M-A[i]) != 0 && A[i] - (M-A[i]) < ans.second - ans.first)
                ans = {A[i], M-A[i]};
        printf("Peter should buy books whose prices are %d and %d.\n\n", ans.first, ans.second);
    }
	return 0;
}

