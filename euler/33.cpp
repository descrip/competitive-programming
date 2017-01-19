//only c?

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans1 = 1, ans2 = 1;
	for (int a = 1; a <= 9; ++a)
		for (int b = 1; b <= 9; ++b)
			for (int c = 1; c <= 9; ++c){
				double r = (double) b / c;
				//cout << a << ' ' << b << ' ' << c << ' ' << r << '\n';
				if (r >= 1)
					continue;
				if (c * (10 * a + b) == b * (10 * a + c)){
					cout << "a " << a << ' ' << b << ' ' << c << ' ' << ans1 << ' ' << ans2 << '\n';
					ans1 *= 10 * a + b;
					ans2 *= 10 * a + c;
				}
				else if (c * (10 * a + b) == b * (10 * c + a)){
					cout << "b " << a << ' ' << b << ' ' << c << ' ' << ans1 << ' ' << ans2 << '\n';
					ans1 *= 10 * a + b;
					ans2 *= 10 * c + a;
				}
				else if (c * (10 * b + a) == b * (10 * a + c)){
					cout << "c " << a << ' ' << b << ' ' << c << ' ' << ans1 << ' ' << ans2 << '\n';
					ans1 *= 10 * b + a;
					ans2 *= 10 * a + c;
				}
				else if (c * (10 * b + a) == b * (10 * c + a)){
					cout << "d " << a << ' ' << b << ' ' << c << ' ' << ans1 << ' ' << ans2 << '\n';
					ans1 *= 10 * b + a;
					ans2 *= 10 * c + a;
				}
			}
	cout << ans2 / __gcd(ans1, ans2) << '\n';
return 0;}

