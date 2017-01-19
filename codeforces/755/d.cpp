#include <bits/stdc++.h>
using namespace std;

int N, K, pos = 1;
long long ft[1000001], C = 1;

long long rsq(int b) {
    long long sum = 0;
    for (; b; b -= (b & (-b)))
        sum += ft[b];
    return sum;
}

long long rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0LL : rsq(a-1));
}

long long rsq2(int a, int b) {
    if (a > b)
        return rsq(a, N) + rsq(1, b);
    else return rsq(a, b);
}

void add(int k, long long v) {
    for (; k < N+1; k += (k & (-k)))
        ft[k] += v;
}

int go(int a, int b) {
    int c = a+b;
    if (c > N)
        c -= N;
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int n = 0; n < N; ++n) {
        add(pos, 1LL);
        add(go(pos, K), 1LL);
        C += rsq2(go(pos, 1), go(pos, K-1)) + 1;
        pos = go(pos, K);
        cout << C << ' ';
    }
    cout << '\n';
    //cout << C << '\n';
    return 0;
}

