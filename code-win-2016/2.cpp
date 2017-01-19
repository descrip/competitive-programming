#include <bits/stdc++.h>
using namespace std;

int N, X;
int A[1000005], B[1000005][23], C[1000005];

int recur(int pos, int exp) {
    /*
    if (pos >= N)
        return recur(pos, );
        */
    //cout << pos << ' ' << exp << '\n';
    if (B[pos][exp] != 0)
        return B[pos][exp];
    else if (pos+(1<<(exp-1)) >= N)
        return (B[pos][exp] = recur(pos, exp-1));
    else return (B[pos][exp] = min(recur(pos, exp-1), recur(pos+(1<<(exp-1)), exp-1)));
}

int calc(int a) {
    int pos = a, ans = 0x7fffffff;
    while (pos < a+X) {
        if (pos+(1<<C[pos]) <= a+X) {
            ans = min(ans, B[pos][C[pos]]);
            pos += (1<<C[pos]);
        }
        else {
            int e = (int)log2((double)(a+X-pos));
            ans = min(ans, B[pos][e]);
            pos += (1<<e);
        }
    }
    return ans;
}

int main() {
    /*
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    */
    cin >> X >> N;

    int LOG = (int)log2((double)N)+1;
    //cout << LOG << '\n';
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B[i][0] = A[i];
    }
    for (int i = 0; i <= 22; ++i) {
        for (int j = 0; j < N; j += (1<<i))
            if (j + (1<<i) < N)
                C[j] = i;
    }

    if (X > N) {
        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans = max(ans, A[i]);
        cout << ans << '\n';
        return 0;
    }


    recur(0, LOG+1);
    /*
    cout << B[0][0] << '\n';
    cout << B[0][1] << '\n';
    cout << B[4][2] << '\n';
    */
    //cout << C[4] << ' ' << B[4][C[4]] << '\n';
    int ans = 0;
    for (int i = 0; i <= N-X; ++i) {
        //cout << i << ' ' << calc(i) << '\n';
        ans = max(ans, calc(i));
    }
    cout << ans << '\n';
	return 0;
}

