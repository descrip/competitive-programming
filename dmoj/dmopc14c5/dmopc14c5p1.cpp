#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int r, h; cin >> r >> h;
	cout.precision(9);
	cout << (1.0/3.0)*(r*r*h*3.1415) << '\n';
return 0;}
