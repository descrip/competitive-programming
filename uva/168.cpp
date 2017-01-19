#include <bits/stdc++.h>
using namespace std;

int main(){
	//cin.sync_with_stdio(0); cin.tie(0);
	vector<int> adj[26];
	bool vis [26];
	char c1, c2;
	int s, t, k, c;
	while (true){
		fill(vis,vis+26,false);
		fill_n(adj,26,vector<int>());
		c = 0;
		cin >> ws; //eat whitespace
		c1 = cin.peek();
		if (c1 == '#') break;
		while (true){
			cin >> c1;
			cin >> c2;
			while (true){
				cin >> c2;
				if (c2 == ';' || c2 == '.') break;
				adj[c1-65].push_back(c2-65);
			}
			if (c2 == '.') break;
		}
		cin >> c1; t = c1-65;
		cin >> c1; s = c1-65;
		cin >> k;
		while (true){
			//cout << (char)(s+65) << ' ' << (char)(t+65) << '\n';
			int temp = t;
			bool ok = false;
			for (int i = 0; i < adj[t].size(); ++i){
				if (!vis[adj[t][i]] && s != adj[t][i]){
					t = adj[t][i];
					ok = true;
					break;
				}
			}
			if (!ok){
				cout << '/' << (char)(65+t) << '\n';
				break;
			} 
			s = temp;
			++c;
			if (c == k){
				vis[s] = true;
				cout << (char)(s+65) << ' ';
				c = 0;
			}
		}
	}
return 0;}
