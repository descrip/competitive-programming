#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (scanf("%d", &N)) {
        if (N == 0) break;
        int X = N, ans = 0;
        for (int i = 2; i*i < X; ++i)
            if (X % i == 0) {
                ++ans;
                while (X % i == 0)
                    X /= i;
            }
        if (X > 1)
            ++ans;
        printf("%d : %d\n", N, ans);
    }
	return 0;
}

