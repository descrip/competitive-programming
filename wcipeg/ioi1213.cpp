#include <bits/stdc++.h>
using namespace std;

char abc[1000005];
int n, par[1000005][22], len[1000005], pos = 0, cnt = 1;
vector<int> hist = {0};

int recur(int a, int b){
	/*
	cout << a << ' ' << b << '\n';
	cout << "r " << par[a][0] << ' ' << par[a][1] << ' ' << par[a][2] << '\n';
	*/
	if (b == 0)
		return a;
	int k = log2(b);
	return recur(par[a][k], b-(1<<k));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	fill_n(par[0], 22*1000005, -1);
	for (int i = 0; i < n; ++i){
		char t; cin >> t;
		if (t == 'T'){
			char l; cin >> l;
			abc[cnt] = l;
			len[cnt] = len[pos]+1;
			par[cnt][0] = pos;
			for (int j = 1; j < 22; ++j)
				if (par[par[cnt][j-1]][j-1] != -1)
					par[cnt][j] = par[par[cnt][j-1]][j-1];
			pos = cnt++;
			hist.push_back(pos);
		}
		else if (t == 'U'){
			int x; cin >> x;
			pos = hist[hist.size() - x - 1];
			hist.push_back(pos);
		}
		else if (t == 'P'){
			int x; cin >> x;
			cout << abc[recur(pos, len[pos]-x-1)] << '\n';
		}
	}
return 0;}
