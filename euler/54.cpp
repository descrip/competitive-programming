//this is divine punishment for my bashing

#include <bits/stdc++.h>
using namespace std;

int rank2int[256];

pair<pair<int,int>,vector<int>> eval(const vector<pair<int,char>> &v){
	vector<int> rv;
	for (int i = 0; i < 5; ++i)
		rv.push_back(v[i].first);
	reverse(rv.begin(), rv.end());

	bool sameSuit = true;
	for (int i = 1; i < 5; ++i)
		if (v[i].second != v[i-1].second)
			sameSuit = false;

	if (sameSuit){
		//royal flush
		if (v[0].first == 10 && v[4].first == 14)
			return {{9, v[4].first}, rv};
		//straight flush
		else if (v[4].first - v[0].first == 4)
			return {{8, v[4].first}, rv};
	}

	//four of a kind
	for (int i = 0; i < 2; ++i)
		for (int j = 1; j < 4; ++j)
			if (v[i].first != v[i+j].first)
				break;
			else if (j == 3)
				return {{7, v[i+j].first}, rv};

	//full house
	if (v[0].first == v[1].first && v[2].first == v[3].first && v[2].first == v[4].first)
		return {{6, v[4].first}, rv};
	else if (v[0].first == v[1].first && v[0].first == v[2].first && v[3].first == v[4].first)
		return {{6, v[2].first}, rv};

	//flush
	if (sameSuit)
		return {{5, v[4].first}, rv};

	//straight
	for (int i = 1; i < 5; ++i)
		if (v[i].first - v[i-1].first != 1)
			break;
		else if (i == 4)
			return {{4, v[4].first}, rv};

	//three of a kind
	for (int i = 0; i < 3; ++i)
		for (int j = 1; j < 3; ++j)
			if (v[i].first != v[i+j].first)
				break;
			else if (j == 2)
				return {{3, v[i+j].first}, rv};

	int numPair = 0, best = 0;
	for (int i = 0; i < 4; ++i)
		if (v[i].first == v[i+1].first){
			++numPair;
			best = max(best, v[i+1].first);
		}

	//two pair
	if (numPair == 2)
		return {{2, best}, rv};
	//one pair
	else if (numPair == 1)
		return {{1, best}, rv};

	return {{0, v[4].first}, rv};
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);

	rank2int['A'] = 14;
	rank2int['K'] = 13;
	rank2int['Q'] = 12;
	rank2int['J'] = 11;
	rank2int['T'] = 10;
	rank2int['9'] = 9;
	rank2int['8'] = 8;
	rank2int['7'] = 7;
	rank2int['6'] = 6;
	rank2int['5'] = 5;
	rank2int['4'] = 4;
	rank2int['3'] = 3;
	rank2int['2'] = 2;

	vector<vector<pair<int,char>>> v (2, vector<pair<int,char>> (5));
	int ans = 0;
	for (int line = 1; line <= 1000; ++line){
		for (int p = 0; p < 2; ++p){
			for (int i = 0; i < 5; ++i){
				char x, y; cin >> x >> y;
				v[p][i] = {rank2int[(int)x], y};
			}
			sort(v[p].begin(), v[p].end());
		}
		if (eval(v[0]) > eval(v[1]))
			++ans;
		//cout << eval(v[0]).first.first << ' ' << eval(v[0]).first.second << ' ' << eval(v[1]).first.first << ' ' << eval(v[1]).first.second << ' ' << ans << '\n';
	}
	cout << ans << '\n';
return 0;}

