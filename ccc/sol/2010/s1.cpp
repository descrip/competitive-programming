#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

bool comp(const pair<int,string> &a, const pair<int,string> &b){
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main(){
	int n;
	scanf("%d",&n);
	if (n == 0)
		return 0;
	vector<pair<int,string>> v;
	for (int i = 0; i < n; ++i){
		string name;
		cin >> name;
		int r, s, d;
		cin >> r >> s >> d;
		v.pb(make_pair(2*r + 3*s + d,name));
	}
	sort(v.begin(),v.end(),comp);
	if (v.size() != 1)
		cout << v[0].second << '\n' << v[1].second << '\n';
	else
		cout << v[0].second << '\n';
	return 0;
}
