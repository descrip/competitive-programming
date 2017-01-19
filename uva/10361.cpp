#include <bits/stdc++.h>
using namespace std;

char A[101], B[101], AA[5][101];
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    cin.getline(A, 101);
    for (int t = 1; t <= T; ++t) {
        cin.getline(A, 101);
        cin.getline(B, 101);
        char* pch = strtok(A, "<>");
        for (int i = 0; i < 5; ++i) {
            strcpy(AA[i], *pch);
            //cout << AA[i] << '\n';
            pch = strtok(NULL, "<>");
        }
    }
    return 0;
}

