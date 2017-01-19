/*
ID: jezhao11
LANG: C++11
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (++n){
		vector<int> dig;
		int m = n;
		while (m){
			dig.push_back(m % 10);
			m /= 10;
		}
		reverse(dig.begin(), dig.end());
		set<int> uniq (dig.begin(), dig.end());
		if (uniq.size() != dig.size())
			continue;

		int a = dig[0], b = 1;
		vector<int> cyc;
		for (int i = 0; i < a; ++i)
			cyc.push_back(dig[(i + b) % dig.size()]);
		while (true){
			a = cyc.back();
			b = find(dig.begin(), dig.end(), a) - dig.begin() + 1;
			cyc.clear();
			if (uniq.size() == 1){
				if (uniq.count(a) == 1){
					cout << n << '\n';
					return 0;
				}
				else break;
			}
			else if (uniq.count(a) == 0)
				break;
			uniq.erase(a);
			for (int i = 0; i < a; ++i)
				cyc.push_back(dig[(i + b) % dig.size()]);
		}
	}
return 0;}
