#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> A;
	for (int i = 0; i < N; ++i){
		char c; int a, b; cin >> c >> a >> b;
		if (c == 'M'){
			A.push_back({a, 1});
			A.push_back({b+1, -1});
		}
		else{
			A.push_back({a, 2});
			A.push_back({b+1, -2});
		}
	}
	sort(A.begin(), A.end());
	int M = 0, F = 0, ans = 0;
	for (int i = 0; i < A.size(); ++i){
		if (A[i].second == -2)
			--F;
		else if (A[i].second == 2)
			++F;
		else if (A[i].second == 1)
			++M;
		else if (A[i].second == -1)
			--M;
		if (A[i].first != A[i+1].first || i == A.size()-1)
			ans = max(ans, min(M, F));
	}
	cout << 2*ans << '\n';
return 0;}

