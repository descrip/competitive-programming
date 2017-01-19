#include <bits/stdc++.h>
using namespace std;

vector<int> dig(int n){
	vector<int> ret;
	while (n > 0){
		ret.push_back(n % 10);
		n /= 10;
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i = 1;
	while (++i)
		if (floor(log10(6*i)+1) == floor(log10(i)+1)){
			vector<int> v = dig(i);
			if (v == dig(2*i) && v == dig(3*i) && v == dig(4*i) && v == dig(5*i) && v == dig(6*i)){
				cout << i << ' ' << 2*i << ' ' << 3*i << ' ' << 4*i << ' ' << 5*i << ' ' << 6*i << '\n';
				return 0;
			}
		}
return 0;}

