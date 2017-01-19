#include <bits/stdc++.h>
using namespace std;

string s, t; 
double ans = 0;
int res = 0;

void canDo(int a, int pos, double prob){
	if (a == t.size()){
		if (pos == res)
			ans += prob;
	}
	else if (t[a] == '+')
		canDo(a+1,pos+1,prob);
	else if (t[a] == '-')
		canDo(a+1,pos-1,prob);
	else{
		canDo(a+1,pos-1,prob/2);
		canDo(a+1,pos+1,prob/2);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	for (char c : s)
		if (c == '+') ++res;
		else --res;
	canDo(0,0,1.0);
	cout << fixed << setprecision(11) << ans << '\n';
return 0;}
