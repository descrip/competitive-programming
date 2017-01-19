#include <bits/stdc++.h>
using namespace std;

int N, C[10], B[782][4];
char A[782];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        fill_n(A, 782, '0');
        fill_n(B[0], 4*782, 0);
        A[0] = '1';
        for (int k = 2; k <= N; ++k) {
            int i = k;
            int shift = 0, carry = 0;
            while (i > 0) {
                int x = i % 10;
                i /= 10;
                for (int j = 0; j < 782; ++j) {
                    int tmp = x * (A[j]-'0') + carry;
                    B[j+shift][shift] = tmp % 10;
                    carry = tmp/10;
                }
                shift++;
            }
            carry = 0;
            for (int j = 0; j < 782; ++j) {
                int tmp = carry;
                for (int l = 0; l < 3; ++l)
                    tmp += B[j][l];
                carry = tmp / 10;
                A[j] = '0' + (tmp % 10);
            }
        }
        /*
        for (int i = 0; i < 20; ++i) 
            cout << A[i];
        cout << '\n';
        for (int i = 0; i < 20; ++i) 
            cout << B[i][0];
        cout << '\n';
        for (int i = 0; i < 20; ++i) 
            cout << B[i][1];
        cout << '\n';
        */
        fill_n(C, 10, 0);
        for (int i = 0; i < 782; ++i)
            C[A[i]-'0']++;
        for (int i = 781; i >= 0; --i)
            if (A[i] == '0') --C[0];
            else break;
        // "the output format isn't too critical"
        cout << N << "! --\n";
        for (int i = 0; i <= 9; ++i) {
            cout << setw(5) << "(" << i << ")" << setw(5) << C[i];
            if (i == 4 || i == 9)
                cout << '\n';
        }
    }
	return 0;
}

