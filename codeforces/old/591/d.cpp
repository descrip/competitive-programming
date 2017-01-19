#include <bits/stdc++.h>
using namespace std;

double x1, usux, x2, y2, vm, t, ax, ay, bx, by;

bool yes(double z){
	double x = x1 + ax * min(t,z), y = usux + ay * min(t,z);
	if (z > t){
		x += bx * (z-t);
		y += by * (z-t);
	}
	return (x2-x)*(x2-x) + (y2-y)*(y2-y) <= vm*vm*z*z;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> x1 >> usux >> x2 >> y2 >> vm >> t >> ax >> ay >> bx >> by;
	double tl = 0, tr = 1e9, mid;
	while (tr - tl > 1e-8){
		mid = tl+(tr-tl)/2;
		if (yes(mid))
			tr = mid;
		else
			tl = mid;
	}
	cout << fixed << setprecision(9) << tl << '\n';
	cout << __gcd(0,0) << '\n';
return 0;}
