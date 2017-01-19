#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A, B;
multiset<long long> possA;

int recur(int pos, long long sum){
	if (sum > *possA.rbegin())
		return 0;
	int ret = possA.count(sum);
	for (int i = pos; i < B.size(); ++i)
		ret += recur(i+1, sum + B[i]);
	//cout << sum << ' ' << ret << '\n';
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i){
		int x; cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < M; ++i){
		int x; cin >> x;
		B.push_back(x);
	}
	if (N > M){
		swap(N, M);
		swap(A, B);
	}
	for (int i = 1; i < (1 << N); ++i){
		long long ret = 0;
		for (int j = 0; j < N; ++j)
			if ((i & (1 << j)) != 0)
				ret += A[j];
		possA.insert(ret);
	}
	cout << recur(0, 0) << '\n';
return 0;}

