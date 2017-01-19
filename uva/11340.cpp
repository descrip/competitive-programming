#include <bits/stdc++.h>
using namespace std;

int N, K, A[261], M;
char S[10005];
long long ans;

int main() {
    scanf("%d ", &N);
    for (int n = 0; n < N; ++n) {
        scanf("%d ", &K);
        fill_n(A, 256, 0);
        for (int k = 0; k < K; ++k) {
            char c; int a;
            scanf("%c %d ", &c, &a);
            //printf("%c %d\n", c, a);
            A[c] = a;
        }
        scanf("%d ", &M);
        ans = 0;
        for (int m = 0; m < M; ++m) {
            fgets(S, 10005, stdin);
            //printf("%d %s", strlen(S), S);
            for (int i = 0; i < strlen(S); ++i)
                ans += A[S[i]];
        }
        printf("%.2f$\n", (double)ans/100);
    }
	return 0;
}

