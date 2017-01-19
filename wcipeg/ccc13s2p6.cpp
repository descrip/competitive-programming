#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int m; string s; cin >> s >> m;
	static long long sum[10001];
	static int last[128];
	static vector<int> copy[128];
	sum[0] = 1;
	for (int i = 1; i <= s.size(); ++i){
		sum[i] = sum[i-1]*2 - sum[last[(int)s[i-1]]-1];
		cout << sum[i] << '\n';
		copy[(int)s[i-1]].push_back(sum[i]-sum[i-1]);
		last[(int)s[i-1]] = i;
	}
	long long ans = 0;
	for (int i = 33; i <= 126; ++i)
		for (int j = 0; j < copy[i].size(); ++j){
			cout << (char)i << ' ' << j << ' ' << copy[i][j] << ' ' << (copy[i].size()-j)*(copy[i].size()-j) << '\n';
			ans = (ans+copy[i][j]*(copy[i].size()-j)*(copy[i].size()-j)) % m;
		}
	cout << (ans+1)%m << '\n';
return 0;}
