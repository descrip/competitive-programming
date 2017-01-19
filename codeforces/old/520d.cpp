#include <bits/stdc++.h>
using namespace std;

struct cube{
	int v, x, y;
	cube (int a, int b, int c) : v(a), x(b), y(c) {}
};

bool operator<(const cube &a, const cube &b){
	return a.v < b.v;
}
bool operator==(const cube &a, const cube &b){
	return (a.x == b.x && a.y == b.y);
}

int m;
set<cube> cubes;
set<cube> leaves;
vector<int> ans;

bool isStable(const cube &c){
	if (cubes.count(c) == 0) return true;
	return (cubes.count(cube(-1,c.x-1,c.y-1)) == 1 ||
			cubes.count(cube(-1,c.x,c.y-1)) == 1 ||
			cubes.count(cube(-1,c.x+1,c.y-1)) == 1);
}

bool canRemove(const cube &c){
	cubes.erase(c);
	bool ok = isStable(cube(-1,c.x-1,c.y+1)) && 
		 isStable(cube(-1,c.x,c.y+1)) && 
		 isStable(cube(-1,c.x+1,c.y+1));
	cubes.insert(c);
	return ok;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> m;
	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		cubes.insert(cube(i,a,b));
	}
	for (auto it = cubes.begin(); it != cubes.end(); ++it){
		if (canRemove(*it))
			leaves.insert(*it);
	}
	for (auto c : leaves){
		cout << c.v << ' ' << c.x << ' ' << c.y << '\n';
	}
	/*
	bool vasya = true;
	while (!cubes.empty()){
		auto r = (vasya ? *leaves.rbegin() : *leaves.begin());
		ans.push_back(r.v);
		auto t = cubes.find(cube(-1,r.x-1,r.y-1));
		if (canRemove(*t))
			leaves.insert(*t);
		t = cubes.find(cube(-1,r.x,r.y-1));
		if (canRemove(*t))
			leaves.insert(*t);
		t = cubes.find(cube(-1,r.x+1,r.y-1));
		if (canRemove(*t))
			leaves.insert(*t);
	}
	*/
	for (int i : ans) cout << i << '\n';
return 0;}
