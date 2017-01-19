#include <bits/stdc++.h>
using namespace std;

long long A[5843]; 
int P[4] = {2, 3, 5, 7};

string suffix(int n) {
    int x = n%10, y = n%100;
    if (y == 11 || y == 12 || y == 13) return "th";
    else if (x == 1) return "st";
    else if (x == 2) return "nd";
    else if (x == 3) return "rd";
    else return "th";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill_n(A, 5843, 0x7fffffff);
    A[0] = 1;
    for (int i = 1; i < 5842; ++i) {
        for (int j = 0; j < i; ++j)
            for (int p = 0; p < 4; ++p)
                if (P[p] * A[j] > A[i-1])
                    A[i] = min(A[i], P[p] * A[j]);
    }
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << "The " << n << suffix(n) << " humble number is " << A[n-1] << ".\n";
    }
    return 0;
}

