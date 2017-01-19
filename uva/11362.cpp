#include <algorithm>
#include <iostream>
using namespace std;

bool isPrefix(string s, string t){
	if (t.size() < s.size()) return false;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != t[i])
			return false;
	return true;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	static string A [10000];
	for (int tc = 0; tc < T; ++tc){
		int N; cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		sort(A,A+N);
		bool ok = true;
		for (int i = 0; i < N-1; ++i)
			if (isPrefix(A[i],A[i+1]))
				ok = false;
		cout << (ok ? "YES\n" : "NO\n");
	}
return 0;}
