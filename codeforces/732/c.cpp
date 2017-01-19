#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long A[3];
    for (int i = 0; i < 3; ++i)
        cin >> A[i];
    long long M = max(A[0]-1, max(A[1]-2, A[2]-1));
    for (int i = 0; i < 3; ++i)
        A[i] = M-A[i];
    //cout << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
    for (int i = 0; i <= 2; i+=2)
        if (A[i] < 0) {
            ++A[i];
            if (A[1] < 0) ++A[1];
        }
    cout << A[0]+(A[1]<0?-A[1]:A[1])+A[2] << '\n';
	return 0;
}

