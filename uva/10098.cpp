#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> S;
        sort(S.begin(), S.end());
        cout << S << '\n';
        while (true) {
            int pvt = S.size()-1;
            while (pvt >= 1 && S[pvt-1] >= S[pvt])
                --pvt;
            if (pvt <= 0)
                break;
            --pvt;
            int ind = S.size()-1;
            while (S[ind] <= S[pvt])
                --ind;
            swap(S[pvt], S[ind]);
            reverse(S.begin()+pvt+1, S.end());
            cout << S << '\n';
        }
        cout << '\n';
    }
	return 0;
}

