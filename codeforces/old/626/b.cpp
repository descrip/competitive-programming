#include <bits/stdc++.h>
using namespace std;

typedef pair<bool, pair<bool, bool>> pbbb;

pbbb dp[201][201][201];
bool vis[201][201][201];

void merge(pbbb &a, const pbbb &b){
	a.first |= b.first;
	a.second.first |= b.second.first;
	a.second.second |= b.second.second;
}

pbbb recur(int r, int g, int b){
	if (vis[r][g][b])
		return dp[r][g][b];
	//cout << r << ' ' << g << ' ' << b << '\n';
	vis[r][g][b] = true;
	pbbb ret = {false, {false, false}};
	if (r > 0 && g > 0)
		merge(ret, recur(r-1, g-1, b+1));
	if (r > 0 && b > 0)
		merge(ret, recur(r-1, g+1, b-1));
	if (g > 0 && b > 0)
		merge(ret, recur(r+1, g-1, b-1));
	if (r >= 2)
		merge(ret, recur(r-1, g, b));
	if (g >= 2)
		merge(ret, recur(r, g-1, b));
	if (b >= 2)
		merge(ret, recur(r, g, b-1));
	if (ret == make_pair(true, make_pair(true, true))){
		cout << "BGR\n";
		exit(EXIT_SUCCESS);
	}
	dp[r][g][b] = ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	for (char C : s)
		if (C == 'R')
			++a;
		else if (C == 'G')
			++b;
		else if (C == 'B')
			++c;
	vis[1][0][0] = vis[0][1][0] = vis[0][0][1] = true;
	dp[1][0][0] = {true, {false, false}};
	dp[0][1][0] = {false, {true, false}};
	dp[0][0][1] = {false, {false, true}};
	pbbb pb = recur(a, b, c);
	//cout << pb.first << ' ' << pb.second.first << ' ' << pb.second.second << '\n';
	if (pb.second.second)
		cout << 'B';
	if (pb.second.first)
		cout << 'G';
	if (pb.first)
		cout << 'R';
	cout << '\n';
return 0;}

