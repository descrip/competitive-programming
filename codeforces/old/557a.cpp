#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ma1, mi1, ma2, mi2, ma3, mi3;
	cin >> mi1 >> ma1 >> mi2 >> ma2 >> mi3 >> ma3;
	int a = mi1, b = mi2, c = mi3;
	while (a + b + c < n){
		if (a < ma1) ++a;
		else if (b < ma2) ++b;
		else if (c < ma3) ++c;
	}
	cout << a << ' ' << b << ' ' << c << '\n';
return 0;}
