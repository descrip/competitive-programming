// {{{ Headers 
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>//#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define pb push_back
#define __ << ' ' <<
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// }}}

bool isLeap(int y){
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	return false;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int y, m, d, h, mi, s; cin >> y >> _ >> m >> _ >> d >> _ >> h >> _ >> mi >> _ >> s;
	int dist = abs(x2-x1)+abs(y2-y1);
	vector<int> mtod = {31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = 1; i <= dist; ++i){
		++s;
		if (s == 60){
			++mi;
			s = 0;
		}
		if (mi == 60){
			++h;
			mi = 0;
		}
		if (h == 24){
			++d;
			h = 0;
		}
		if (d > (isLeap(y) && m == 2 ? 29 : mtod[m-1])){
			++m;
			d = 1;
		}
		if (m > 12){
			++y;
			m = 1;
		}
	}
	cout << setw(4) << setfill('0') << y << ':';
	cout << setw(2) << setfill('0') << m << ':';
	cout << setw(2) << setfill('0') << d << ':';
	cout << setw(2) << setfill('0') << h << ':';
	cout << setw(2) << setfill('0') << mi << ':';
	cout << setw(2) << setfill('0') << s << '\n';
	return 0;}
