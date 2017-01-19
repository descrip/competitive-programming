#include <bits/stdc++.h>
using namespace std;

const int LIM = 2e7;
int N, cnt = 0, S;
bool P[LIM+1];
pair<int, int> Z[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill_n(P, LIM, true);
    P[0] = P[1] = false;
    for (int i = 2; i*i <= LIM; ++i)
        if (P[i])
            for (int j = 2; i*j <= LIM; ++j)
                P[i*j] = false;
    for (int i = 3; i+2 <= LIM && cnt < 1e5; ++i)
        if (P[i] && P[i+2])
            Z[cnt++] = {i, i+2};
    //cout << cnt << '\n';
    while (cin >> S)
        cout << '(' << Z[S-1].first << ", " << Z[S-1].second << ")\n";
    return 0;
}

