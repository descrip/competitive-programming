#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream fin ("empty.in");
	ofstream fout ("empty.out");
	int n, k; fin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; ++i)
		s.insert(i);
	for (int i = 0; i < k; ++i){
		int x, y, a, b; fin >> x >> y >> a >> b;
		for (int j = 1; j <= y; ++j){
			auto it = s.lower_bound(((long long)a*j+b) % n);
			for (int l = 0; l < x; ++l){
				if (it == s.end())
					it = s.begin();
				auto it2 = it;
				++it;
				s.erase(it2);
				/*
				for (int m : s)
					fout << m << ' ';
				fout << '\n';
				*/
			}
		}
	}
	fout << *s.begin() << '\n';
	fin.close(); fout.close();
return 0;}
