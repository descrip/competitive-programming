#include <bits/stdc++.h>
using namespace std;

int recur(int a, int b, int c, int d, int e, int f){
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
		return 0;
	else if (a == 0 && c == 0 && e == 0)
		return b*b;
	else if (b == 0 && d == 0 && f == 0)
		return a*a;
	else
		return 2*(a+b+c+d+e+f)-6 + recur(a-1,b-1,c-1,d-1,e-1,f-1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << recur(a,b,c,d,e,f) << '\n';
return 0;}
