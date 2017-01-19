#include <cstdio>
#include <algorithm>
#define INF 999999999 
using namespace std;

int main(){
	int n, x1, x2, y1, y2, a[1024][1024], b[512][512];
	scanf("%d %d %d",&n,&y1,&x1);
	for (int y = 0; y < y1; ++y)
		for (int x = 0; x < x1; ++x)
			scanf("%d",&a[y][x]);
	for (int i = 0; i < n - 1; ++i){
		scanf("%d %d",&y2,&x2);
		for (int y = 0; y < y2; ++y)
			for (int x = 0; x < x2; ++x)
				scanf("%d",&b[y][x]);
		for (int ay = y1 - 1; ay >= 0; ay--)
			for (int ax = x1 - 1; ax >= 0; ax--)
				for (int by = y2 - 1; by >= 0; by--)
					for (int bx = x2 - 1; bx >= 0; bx--){
						//printf("%d %d %d %d %d %d\n",ax,ay,bx,by,ay * y2 + by,ax * x2 + bx);
						a[ay * y2 + by][ax * x2 + bx] = a[ay][ax] * b[by][bx];
					}
		y1 *= y2;
		x1 *= x2;
	}
	/*
	printf("%d %d\n",x1,y1);
	for (int y = 0; y < y1; ++y)
		for (int x = 0; x < x1; ++x)
			printf("%d%c",a[y][x],(x == x1 - 1) ? '\n' : ' ');
	*/
	int maxrowsum = -INF, minrowsum = INF, maxcolsum = -INF, mincolsum = INF, minele = INF, maxele = -INF, tempsum;
	for (int y = 0; y < y1; ++y){
		tempsum = 0;	
		for (int x = 0; x < x1; ++x){
			minele = min(minele,a[y][x]);
			maxele = max(maxele,a[y][x]);
			tempsum += a[y][x];
		}
		maxrowsum = max(maxrowsum,tempsum);
		minrowsum = min(minrowsum,tempsum);
	}
	for (int x = 0; x < x1; ++x){
		tempsum = 0;
		for (int y = 0; y < y1; ++y)
			tempsum += a[y][x];
		maxcolsum = max(maxcolsum,tempsum);
		mincolsum = min(mincolsum,tempsum);
	}
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",maxele,minele,maxrowsum,minrowsum,maxcolsum,mincolsum);
	return 0;
}
