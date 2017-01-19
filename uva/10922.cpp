#include <bits/stdc++.h>
using namespace std;

char N[1001];
int depth;
bool ans;

void recur(int s, int d = 1) {
    if (s < 10) {
        ans = (s == 9);
        depth = d;
        return;
    }
    int t = 0;
    while (s > 0) {
        t += s % 10;
        s /= 10;
    }
    recur(t, d+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (strcmp(N, "0") == 0) break;
        int S = 0;
        for (int i = 0; i < strlen(N); ++i)
            S += N[i] - '0';
        recur(S);
        if (ans)
            cout << N << " is a multiple of 9 and has 9-degree " << depth << ".\n";
        else
            cout << N << " is not a multiple of 9.\n";
    }
    return 0;
}

