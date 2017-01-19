#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
	return (a /  __gcd(a, b)) * b;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long t, w, b; cin >> t >> w >> b;
	long long p = 0, curr = lcm(b, w);
	int r = min(w,b) - 1;
	if (w < b)
		swap(b, w);
	if (b == 1){
		if (w > t)
			p = 0;
		else
			p = (t - curr) / w + 1;
	}
	else if (w > t && b > t)
		p = 0;
	else if (w == b){
		p += (t - w) / w + 1;
	}
	else{
		while (curr <= t){
			int tmp = curr;
			while (tmp <= t){
				p += 1 + min(t - tmp, r);
				if ((double)t / tmp < curr)
					break;
				tmp *= curr;
			}
			if ((double)t / curr < b)
				break;
			curr *= b;
		}
	}
	cout << p << '\n';
	p += min(min(w,b) - 1, t);
	long long g = __gcd(p, t);
	cout << (p / g) << '/' << (t / g) << '\n';
return 0;}
