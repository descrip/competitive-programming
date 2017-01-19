#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dist(const pair<ll, ll> &a, const pair<ll, ll> &b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long double slope(const pair<ll, ll> &a, const pair<ll, ll> &b){
	return (double)(b.second - a.second) / (b.first - a.first);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<pair<ll, ll>, int>> V (N);
	for (int i = 0; i < N; ++i){
		cin >> V[i].first.first >> V[i].first.second;
		V[i].second = i+1;
	}
	sort(V.begin(), V.end());
	for (int i = 2; i < N; ++i)
		if (slope(V[i].first, V[i-1].first) != slope(V[i].first, V[i-2].first)){
			cout << V[i].second << ' ' << V[i-1].second << ' ' << V[i-2].second << '\n';
			break;
		}
return 0;}

