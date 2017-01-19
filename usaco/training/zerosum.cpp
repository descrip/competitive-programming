#include <bits/stdc++.h>
using namespace std;

void dfs(int a, int b, int wait, int sum, string str){
	if (a == b+1){
		if (sum == 0)
			cout << str << '\n';
		return;
	}
	dfs(a+1, b, sum+a, str+"+"+(char)('0'+a));
	dfs(a+1, b, sum-a, str+"-"+(char)('0'+a));
	dfs(a+1, b, sum*10+a, str+" "+(char)('0'+a));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	dfs(2, N, 1, "1");
return 0;}

