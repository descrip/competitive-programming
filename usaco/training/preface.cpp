/*
ID: jezhao11
LANG: C++11
TASK: preface
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,string>> v = {
		{1000, "M"},
		{900, "CM"},
		{500, "D"},
		{400, "CD"},
		{100, "C"},
		{90, "XC"},
		{50, "L"},
		{40, "XL"},
		{10, "X"},
		{9, "IX"},
		{5, "V"},
		{4, "IV"},
		{1, "I"}
	};
	map<char,int> m;
	for (int i = 1; i <= n; ++i){
		int r = i;
		for (auto p : v) while (p.first <= r){
			r -= p.first;
			for (char j : p.second)
				++m[j];
		}
	}
	vector<char> w = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	for (int i = 0; i < w.size(); ++i)
		if (m[w[i]] != 0)
			cout << w[i] << ' ' << m[w[i]] << '\n';
return 0;}
