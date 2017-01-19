#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <random>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define inf (1 << 30)
#define lc(x) (x << 1)
#define rc(x) ((x << 1) | 1)
#define m(a,b) ((a + b) / 2)
#define EPS 1e-6
#define PI 3.1415926535897932384
#define For(a, b, c) for(int a = b; a <= c; a ++)
#define Rev(a, b, c) for(int a = b; a >= c; a --)
#define pb push_back
#define mp make_pair
#define io cin.sync_with_stdio(0); cin.tie(0);
#define MTRAND mt19937 gen(4)
#define RNG(l, h) gen() % (h - l + 1) + l
using namespace std;
const int MAXN =  205, MOD = 1e9 + 7;
typedef pair<int,int> pii;

int cnt[3], N; string S;
int dp[MAXN][MAXN][MAXN];
int solve(int R, int G, int B) {
        if (!R && !G && B == 1) return (1 << 0);
        if (!R && !B && G == 1) return (1 << 1);
        if (!G && !B && R == 1) return (1 << 2);
        if (!R && !G && !B) return 0;
        if (dp[R][G][B] != -1)
                return dp[R][G][B];
        int ret = 0;
        if (R > 0 && G > 0)
                ret |= solve(R - 1, G - 1, B + 1);
        if (R > 0 && B > 0)
                ret |= solve(R - 1, G + 1, B - 1);
        if (G > 0 && B > 0)
                ret |= solve(R + 1, G - 1, B - 1);
        if (R > 1)
                ret |= solve(R - 1, G, B);
        if (G > 1)
                ret |= solve(R, G - 1, B);
        if (B > 1)
                ret |= solve(R, G, B - 1);
        return dp[R][G][B] = ret;
}
int main() { io
        cin >> N >> S;
        For(i, 0, N - 1) {
                if (S[i] == 'R') cnt[0] ++;
                if (S[i] == 'G') cnt[1] ++;
                if (S[i] == 'B') cnt[2] ++;
        }
        memset(dp, -1, sizeof dp);
        int ans = solve(cnt[0], cnt[1], cnt[2]);
        string A;
        if (ans & (1 << 0)) {
                A += 'B';
        }
        if (ans & (1 << 1)) {
                A += 'G';
        }
        if (ans & (1 << 2)) {
                A += 'R';
        }
        cout << A << endl;
}
