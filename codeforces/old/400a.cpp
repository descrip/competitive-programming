#include <bits/stdc++.h>
using namespace std;

string s;

bool canDo(int a, int b){
	for (int x = 0; x < b; ++x){
		for (int y = 0; y < a; ++y)
			if (s[y*b+x] == 'O')
				break;
			else if (y == a-1)
				return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v = {1,2,3,4,6,12};
	for (int ts = 0; ts < n; ++ts){
		cin >> s;
		stringstream ss;
		int cnt = 0;
		for (int i : v)
			if (canDo(i,12/i)){
				ss << i << 'x' << 12/i << ' ';
				++cnt;
			}
		cout << cnt << ' ' << ss.str() << '\n';
	}
return 0;}
