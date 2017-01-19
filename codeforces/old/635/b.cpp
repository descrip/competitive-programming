#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> A (N), B (N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> B[i];
	A.erase(find(A.begin(), A.end(), 0));
	B.erase(find(B.begin(), B.end(), 0));
	int os = find(A.begin(), A.end(), B[0]) - A.begin();
	/*
	for (int i : A)
		cout << i << '\n';
	for (int i : B)
		cout << i << '\n';
		*/
	for (int i = 0; i < N-1; ++i){
		if (A[(os+i)%(N-1)] != B[i]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
return 0;}

