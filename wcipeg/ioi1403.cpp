#include <bits/stdc++.h>
using namespace std;

int n, ax, ay;

void recur(int x, int y, int l, int a, bool cont){
	//cout << "z " << x << ' ' << y << ' ' << l << ' ' << a << ' ' << cont << '\n';
	if (l == 2){
		if (cont){
			vector<pair<int,int>> v = {{x,y}, {x+1,y}, {x,y+1}, {x+1,y+1}};
			v.erase(find(v.begin(),v.end(),make_pair(ax,ay)));
			for (auto i : v)
				printf("%d %d ",i.first,i.second);
			printf("\n");
		}
		else{
			if (a == 0)
				printf("%d %d %d %d %d %d\n", x, y+1, x+1, y+1, x+1, y);
			else if (a == 1)
				printf("%d %d %d %d %d %d\n", x, y, x, y+1, x+1, y+1);
			else if (a == 2)
				printf("%d %d %d %d %d %d\n", x, y, x, y+1, x+1, y);
			else if (a == 3)
				printf("%d %d %d %d %d %d\n", x, y, x+1, y, x+1, y+1);
		}
	}
	else{
		recur(x+l/2, y+l/2, l/2, (a==2)?2:0, cont && (a==2));
		recur(x, y+l/2, l/2, (a==3)?3:1, cont && (a==3));
		recur(x, y, l/2, (a==0)?0:2, cont && (a==0));
		recur(x+l/2, y, l/2, (a==1)?1:3, cont && (a==1));
		if (a == 2)
			printf("%d %d %d %d %d %d\n",
				x+l/2, y+l/2-1, x+l/2-1, y+l/2, x+l/2-1, y+l/2-1);
		else if (a == 3)
			printf("%d %d %d %d %d %d\n",
				x+l/2, y+l/2, x+l/2, y+l/2-1, x+l/2-1, y+l/2-1);
		else if (a == 0)
			printf("%d %d %d %d %d %d\n",
				x+l/2-1, y+l/2, x+l/2, y+l/2, x+l/2, y+l/2-1);
		else if (a == 1)
			printf("%d %d %d %d %d %d\n",
				x+l/2-1, y+l/2-1, x+l/2-1, y+l/2, x+l/2, y+l/2);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> ax >> ay;
	int l = 1<<n;
	if (ax >= l/2 && ay >= l/2)
		recur(0,0,l,2,true);
	else if (ax < l/2 && ay >= l/2)
		recur(0,0,l,3,true);
	else if (ax < l/2 && ay < l/2)
		recur(0,0,l,0,true);
	else if (ax >= l/2 && ay < l/2)
		recur(0,0,l,1,true);
return 0;}
