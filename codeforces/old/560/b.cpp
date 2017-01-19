#include <bits/stdc++.h>
using namespace std;

bool canDo(int x1, int y1, int x2, int y2, int xb, int yb){
	if ((x1+x2 <= xb && y1 <= yb && y2 <= yb) ||
		(y1+y2 <= yb && x1 <= xb && x2 <= xb))
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x1, y1, x2, y2, xb, yb;
	cin >> xb >> yb >> x1 >> y1 >> x2 >> y2;
	cout << (canDo(x1,y1,x2,y2,xb,yb) || canDo(x1,y1,y2,x2,xb,yb)
			|| canDo(y1,x1,x2,y2,xb,yb) || canDo(y1,x1,y2,x2,xb,yb) ? "YES\n" : "NO\n");
return 0;}
