#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int N, C[MAXN], D[MAXN], pos = -1;
long long M[MAXN], m[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int c, d; cin >> c >> d;
        if (pos == -1 || D[pos] != d)
            D[++pos] = d;
        C[pos] += c;
    }
    ++pos;
    for (int i = 0; i < pos-1; ++i)
        if ((C[i] > 0 && D[i] == 1 && D[i+1] == 2) || (C[i] < 0 && D[i] == 2 && D[i+1] == 1)) {
            cout << "Impossible\n"; return 0;
        }
    M[0] = (D[0] == 2 ? 1899LL : (1LL << 60));
    m[0] = (D[0] == 1 ? 1900LL : -(1LL << 60));
    for (int i = 1; i < pos; ++i) {
        M[i] = M[i-1] + C[i-1];
        m[i] = m[i-1] + C[i-1];
        if (D[i] == 1)
            m[i] = max(m[i], 1899LL);
        if (D[i] == 2)
            M[i] = min(M[i], 1900LL);
        cout << i << ' ' << M[i] << ' ' << m[i] << '\n';
    }
	return 0;
}

