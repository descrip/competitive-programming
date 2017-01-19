#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> T;
	vector<int> st, r;
	for (int t = 0; t < T; ++t){
		cin >> N;
		st.clear(); r.clear();
		for (int i = 0; i < N; ++i){
			int x; cin >> x;
			r.push_back(x);
		}
		int need = 1;
		while (need <= N){
			if (!r.empty() && r.back() == need){
				r.pop_back();
				++need;
			}
			else if (!st.empty() && st.back() == need){
				st.pop_back();
				++need;
			}
			else if (r.empty())
				break;
			else{
				st.push_back(r.back());
				r.pop_back();
			}
		}
		cout << (need == N+1 ? "Y" : "N") << '\n';
	}
return 0;}

