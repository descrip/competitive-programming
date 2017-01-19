#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
	return (a /  __gcd(a, b)) * b;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long t, w, b; cin >> t >> w >> b;
	long long p = 0, curr = lcm(w, b), r = min(w, b) - 1;
	if (r > t)
		r = 0;
	if (b < w)
		swap(b, w);
	if (w == 1){
		if (b > t)
			p = 0;
		else
			p = (t - curr) / b + 1;
	}
	else{
		while (curr <= t){
			cout << curr << '\n';
			long long tmp = curr;
			while (tmp <= t){
				p += 1 + min(t - tmp, r);
				if ((double) t / tmp < w)
					break;
				tmp *= w;
			}
			if ((double) t / curr < b)
				break;
			curr *= b;
		}
	}
	//cout << p << '\n';
	p += r;
	long long g = __gcd(p, t);
	cout << p / g << '/' << t / g << '\n';
return 0;}
