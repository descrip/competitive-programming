#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;

int valid(int n, int inputSeq[]){
	set<int> s;
	for (int i = 0; i < n; ++i){
		if (s.count(inputSeq[i]) == 0)
			s.insert(inputSeq[i]);
		else return 0;
		--inputSeq[i];
	}
	int pos = 0;
	for (; pos < n; ++pos){
		if (0 <= inputSeq[pos] && inputSeq[pos] < n) break;
		else if (pos == n-1) return 1;
	}
	for (int i = pos+1; i < n; ++i){
		if (0 <= inputSeq[i] && inputSeq[i] < n && ((inputSeq[pos]+i-pos+n) % n + n) % n != inputSeq[i])
			return 0;
	}
	return 1;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]){
	for (int i = 0; i < n; ++i)
		--gondolaSeq[i];
	int pos = 0, prevSeq[100000];
	for (; pos < n; ++pos){
		if (0 <= gondolaSeq[pos] && gondolaSeq[pos] < n){
			for (int i = 0; i < n; ++i)
				prevSeq[i] = ((gondolaSeq[pos]+i-pos) % n + n) % n;
			break;
		}
		else if (pos == n-1){
			for (int i = 0; i < n; ++i)
				prevSeq[i] = i;
		}
	}
	vector<pair<int,int>> repl;
	int hidden = n, rpos = 0;
	for (int i = 0; i < n; ++i){
		if (gondolaSeq[i] != prevSeq[i])
			repl.push_back({gondolaSeq[i]+1,prevSeq[i]+1});
	}
	sort(repl.begin(),repl.end());
	for (int i = 0; i < repl.size(); ++i){
		while (repl[i].second != repl[i].first){
			replacementSeq[rpos++] = repl[i].second;
			repl[i].second = ++hidden;
		}
	}
	return rpos;
}

long long fastpow(long long a, long long b){
	if (b == 0 || a == 1) return 1;
	else if (b == 1) return a;
	else if (b == 2) return (a*a) % MOD;
	else if (b%2 == 1) return (a*fastpow(a,b-1)) % MOD;
	else{
		long long ret = fastpow(a,b/2);
		return (ret * ret) % MOD;
	}
}

int countReplacement(int n, int inputSeq[]){
	if (!valid(n,inputSeq)) return 0;
	vector<int> v = {n-1};
	for (int i = 0; i < n; ++i)
		if (!(0 <= inputSeq[i] && inputSeq[i] < n))
			v.push_back(inputSeq[i]);
	sort(v.begin(),v.end());
	long long ans = (v.size()-1 == n) ? n : 1;
	for (int i = 1; i < v.size(); ++i)
		ans = (ans * fastpow(v.size()-i,v[i]-v[i-1]-1)) % MOD;
	return ans;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t, n, seq[100000]; cin >> t >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	if (1 <= t && t <= 3){
		cout << valid(n,seq) << '\n';
	}
	else if (4 <= t && t <= 6){
		int retSeq[200000], ans = replacement(n,seq,retSeq);
		cout << ans << ' ';
		for (int i = 0; i < ans; ++i)
			cout << retSeq[i] << ' ';
		cout << '\n';
	}
	else if (7 <= t && t <= 10){
		cout << countReplacement(n,seq) << '\n';
	}
	return 0;
}
