#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
vector<char> id;
char a[100][100];
int w, e, f;

bool fit(int i, int x, int y){
	//cout << i << ' ' << x << ' ' << y << '\n';
	if (i == 2){
		if (x == v[i].first && y == v[i].second){
			for (int j = w-y; j < w-y+v[i].second; ++j)
				for (int z = w-x; z < w-x+v[i].first; ++z)
					a[j][z] = id[i];
			return true;
		}
		else if (x == v[i].second && y == v[i].first){
			//cout << v[i].first << ' ' << v[i].second << '\n';
			for (int j = w-y; j < w-y+v[i].first; ++j)
				for (int z = w-x; z < w-x+v[i].second; ++z)
					a[j][z] = id[i];
			return true;
		}
		else return false;
	}
	for (int y = 0; y < 100; ++y)
		for (int x = 0; x < 100; ++x)
			a[y][x] = id[i-1];
	if (x >= v[i].first && y >= v[i].second){
		for (int j = f; j < f+v[i].second; ++j)
			for (int z = e; z < e+v[i].first; ++z)
				a[j][z] = id[i];
		if (x == v[i].first){
			if (fit(i+1, x, y - v[i].second))
				return true;
		}
		if (y == v[i].second){
			if (fit(i+1, x - v[i].first, y))
				return true;
		}
	}
	for (int y = 0; y < 100; ++y)
		for (int x = 0; x < 100; ++x)
			a[y][x] = id[i-1];
	if (x >= v[i].second && y >= v[i].first){
		for (int j = f; j < f+v[i].first; ++j)
			for (int z = e; z < e+v[i].second; ++z){
				a[j][z] = id[i];
			}
		if (x == v[i].second){
			if (fit(i+1, x, y - v[i].first))
				return true;
		}
		if (y == v[i].first){
			if (fit(i+1, x - v[i].second, y))
				return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 3; ++i){
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}
	id = {'A','B','C'};
	for (int z = 0; z < 3; ++z){
	//do{
		bool did = false;
		if (v[0].second > v[0].first){
			int tmp = v[0].first;
			v[0].first = v[0].second;
			v[0].second = tmp;
			did = true;
			//swap(v[0].first,v[0].second);
		}
		w = v[0].first;
		e = 0;
		f = v[0].second;
		if (fit(1, v[0].first, v[0].first-v[0].second)){
			cout << w << '\n';
			for (int y = 0; y < w; ++y){
				for (int x = 0; x < w; ++x)
					cout << a[y][x];
				cout << '\n';
			}
			return 0;
		}
		w = v[0].second;
		e = v[0].first;
		f = 0;
		if (fit(1, v[0].first-v[0].second, v[0].first)){
			cout << w << '\n';
			for (int y = 0; y < w; ++y){
				for (int x = 0; x < w; ++x)
					cout << a[y][x];
				cout << '\n';
			}
			return 0;
		}
		if (did){
			int tmp = v[0].first;
			v[0].first = v[0].second;
			v[0].second = tmp;
		}
		v.push_back(v[0]);
		v.erase(v.begin());
		id.push_back(id[0]);
		id.erase(id.begin());
	}
	//} while (next_permutation(v.begin(), v.end()) && next_permutation(id.begin(),id.end()));
	cout << -1 << '\n';
return 0;}
