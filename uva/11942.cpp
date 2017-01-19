#include <bits/stdc++.h>
using namespace std;

int N, A[10], B[10];

int main() {
    cin >> N;
    cout << "Lumberjacks:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> A[j];
            B[j] = A[j];
        }
        sort(B, B+10);
        if (equal(A, A+10, B))
        	cout << "Ordered\n";
        else {
        	reverse(B, B+10);
        	if (equal(A, A+10, B))
        		cout << "Ordered\n";
        	else
        		cout << "Unordered\n";
        }
    }
}
