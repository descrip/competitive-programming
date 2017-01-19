#include <bits/stdc++.h>
using namespace std;

bool recur(string a, string b){
	if (a == b)
		return true;
	else if (a.size()%2 == 0){
		int n = a.size()/2;
		//return (recur(a.substr(0,n),b.substr(0,n)) && recur(a.substr(n),b.substr(n))) || (recur(a.substr(0,n),b.substr(n)) && recur(a.substr(n),b.substr(0,n)));
		return (recur(a.substr(0,n),b.substr(n)) && recur(a.substr(n),b.substr(0,n))) || (recur(a.substr(0,n),b.substr(0,n)) && recur(a.substr(n),b.substr(n)));
	}
	else return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b; cin >> a >> b;
	cout << (recur(a,b) ? "YES" : "NO") << '\n';
return 0;}
