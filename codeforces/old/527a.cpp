#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

long long recur(long long a, long long b){
	if (a == 0 || b == 0) return 0;
	if (a == b) return 1;
	long long x = max(a,b), y = min(a,b);
	return (x / y) + recur(x % y,y);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	long long a, b; cin >> a >> b;
	cout << recur(a,b) << '\n';
return 0;}
