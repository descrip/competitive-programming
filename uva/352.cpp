#include <bits/stdc++.h>
using namespace std;

int N, T = 1;
bool A[26][26];

void dfs(int x, int y) {
    A[y][x] = false;
    for (int c = -1; c <= 1; ++c)
        for (int d = -1; d <= 1; ++d)
            if (0 <= y+c && y+c < N && 0 <= x+d && x+d < N && A[y+c][x+d])
                dfs(x+d, y+c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> N) {
        for (int y = 0; y < N; ++y)
            for (int x = 0; x < N; ++x) {
                char c; cin >> c;
                A[y][x] = (c == '1');
            }
        int ans = 0;
        for (int y = 0; y < N; ++y)
            for (int x = 0; x < N; ++x)
                if (A[y][x]) {
                    dfs(x, y);
                    ++ans;
                }
        cout << "Image number " << T++ << " contains " << ans << " war eagles.\n";
    }
	return 0;
}

