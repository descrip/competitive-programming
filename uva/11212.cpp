#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*
	vector<int> v = {1,2,3,4,5,6,7,8,9}, b, c, d, e;
	map<vector<int>, int> vis;
	deque<vector<int>> q;
	set<vector<int>> s;
	q.push_back(v);
	vis[v] = 1;
	s.insert(v);
	while (!q.empty()){
		b = q.front(); q.pop_front();
		for (int i = 0; i < b.size(); ++i)
			for (int j = i; j < b.size(); ++j){
				c.clear(); d.clear();
				for (int k = 0; k < b.size(); ++k)
					if (i <= k && k <= j)
						d.push_back(b[k]);
					else
						c.push_back(b[k]);
				if (c.empty() || d.empty())
					continue;
				for (int k = 0; k <= c.size(); ++k){
					e = c;
					c.insert(c.begin()+k, d.begin(), d.end());
					if (vis[c] == 0 || vis[b]+1 < vis[c]){
						vis[c] = vis[b]+1;
						if (s.count(c) == 0){
							q.push_back(c);
							s.insert(c);
						}
					}
					c = e;
				}
			}
	}
	int ans = 0;
	do{
		ans = max(ans, vis[v]);
	} while(next_permutation(v.begin(), v.end()));
	cout << ans << '\n';
	*/
	vector<int> B, C, D, E;
	while (true){
		int N; cin >> N;
		if (N == 0)
			break;
		vector<int> A, F;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		F = A;
		sort(F.begin(), F.end());
		queue<vector<int>> Q;
		set<pair<vector<int>, int>> S;
		Q.push(A);
		S.insert({A, 0});
		for (int t = 1; t <= 2; ++t){
			B = Q.front(); Q.pop();
			for (int i = 0; i < B.size(); ++b)
				for (int j = i; j < B.size(); ++j){
					C.clear(); D.clear();
					for (int k = 0; k < B.size(); ++k)
						if (i <= k && k <= j)
							D.push_back(B[k]);
						else
							C.push_back(B[k]);
					if (C.empty() || D.empty())
						continue;
					for (int k = 0; k <= C.size(); ++k){
						E = C;
						C.insert(C.begin() + k, D.begin(), D.end());
						if (S.count(C) == 0){
							Q.push(C);
							S.insert({C, t});
						}
					}
				}
		}
		while (!Q.empty())
			Q.pop();
		Q.push(F);
		for (int t = 3; t <= 4; ++t){
			B = Q.front(); Q.pop();
			for (int i = 0; i < B.size(); ++b)
				for (int j = i; j < B.size(); ++j){
					C.clear(); D.clear();
					for (int k = 0; k < B.size(); ++k)
						if (i <= k && k <= j)
							D.push_back(B[k]);
						else
							C.push_back(B[k]);
					if (C.empty() || D.empty())
						continue;
					for (int k = 0; k <= C.size(); ++k){
						E = C;
						C.insert(C.begin() + k, D.begin(), D.end());
						if (S.count(C) == 0){
							Q.push(C);
							S.insert({C, t});
						}
					}
				}
			auto it = S.lower_bound(make_pair(F, -1));
		}
	}
return 0;}

