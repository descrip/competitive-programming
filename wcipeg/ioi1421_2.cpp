#include <bits/stdc++.h>
using namespace std;

const long long MOD = 10e8+9;
const int NMAX = 10e4+5;
int t, n, seq[NMAX];

bool valid(){
	set<int> check;
	for (int i = 0; i < n; ++i){
		if (check.count(seq[i]) == 0)
			check.insert(seq[i]);
		else
			return 0;
	}
	int pos = 0;
	for (; pos < n; ++pos){
		if (0 <= seq[pos] && seq[pos] < n)
			break;
		else if (pos == n-1)
			return 1;
	}
	for (int i = 0; i < n; ++i)
		if (0 <= seq[i] && seq[i] < n && (seq[pos]+i-pos) % n != seq[i])
			return 0;
	return 1;
}

void replacement(){
	int pos = 0;
	for (; pos < n; ++pos)
		if (0 <= seq[pos] && seq[pos] < n)
			break;
	vector<pair<int,int>> repl;
	for (int i = 0; i < n; ++i)
		if (!(0 <= seq[i] && seq[i] < n))
			repl.push_back({seq[i], (seq[pos]+i-pos+n)%n});
	sort(repl.begin(), repl.end());
	vector<int> ans;
	int curr = n;
	for (auto p : repl){
		ans.push_back(p.second);
		while (curr != p.first)
			ans.push_back(curr++);
		curr = p.first+1;
	}
	cout << ans.size() << ' ';
	for (int i : ans)
		cout << i+1 << ' ';
	cout << '\n';
}

long long fastpow(long long a, long long b){
	if (b == 0) return 1;
	else if (b == 1) return a % MOD;
	//else if (b == 2) return (a*a) % MOD;
	else if (b % 2 == 0){
		long long x = fastpow(a, b/2);
		return (x*x) % MOD;
	}
	else if (b % 2 == 1) return (a * fastpow(a,b-1)) % MOD;
}

long long countReplacement(){
	if (!valid()) return 0;
	vector<long long> v = {n-1};
	for (int i = 0; i < n; ++i)
		if (!(0 <= seq[i] && seq[i] < n))
			v.push_back(seq[i]);
	sort(v.begin(), v.end());
	long long ans = (v.size()-1 == n ? n : 1);
	for (int i = 1; i < v.size(); ++i)
		ans = (ans * fastpow(v.size()-i, v[i]-v[i-1]-1)) % MOD;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t >> n;
	for (int i = 0; i < n; ++i){
		cin >> seq[i];
		--seq[i];
	}
	if (1 <= t && t <= 3)
		cout << valid() << '\n';
	else if (4 <= t && t <= 6)
		replacement();
	else if (7 <= t && t <= 10)
		cout << countReplacement() << '\n';
return 0;}
