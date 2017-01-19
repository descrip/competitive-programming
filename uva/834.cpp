#include <bits/stdc++.h>
using namespace std;

int A, B;
vector<int> V;

void recur(int A, int B) {
    if (B == 0)
        return;
    V.push_back(A / B);
    A %= B;
    recur(B, A);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> A >> B) {
        V.clear();
        recur(A, B);
        cout << '[' << V[0];
        if (V.size() > 1)
            cout << ';';
        for (int i = 1; i < V.size(); ++i)
            cout << V[i] << (i == V.size()-1 ? "" : ",");
        cout << "]\n";
    }
	return 0;
}

