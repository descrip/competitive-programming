#include <bits/stdc++.h>
using namespace std;

long long mx, my, sw, sy, bw;

long long lcm(long long a, long long b){
	return a*b / __gcd(a,b);
}

void prin(int a, int b, char c){
	for (int j = 0; j < my*b; ++j){
		for (int i = 0; i < bw; ++i)
			cout << c;
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	sw = lcm(lcm(x1,x2),x3), sy = y1+y2+y3, bw = lcm(sw,sy);
	mx = bw / sw; my = bw / sy;
	cout << bw << '\n';
	prin(x1,y1,'A');
	prin(x2,y2,'B');
	prin(x3,y3,'C');
return 0;}

