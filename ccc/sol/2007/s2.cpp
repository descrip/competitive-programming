#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, m, b[1000][3], t[3];
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d",&b[i][0],&b[i][1],&b[i][2]);
		sort(b[i],b[i]+3);
	}
	scanf("%d",&m);
	for (int i = 0; i < m; i++){
		scanf("%d %d %d",&t[0],&t[1],&t[2]);
		sort(t,t+3);
		long best = 8000000000;
		int j;
		bool fit = false;
		for (j = 0; j < n; j++){
			int k;
			for (k = 0; k < 3; k++)
				if (b[j][k] < t[k])
					break;
			if (k == 3){
				best = min(best,(long)(b[j][0] * b[j][1] * b[j][2]));
				fit = true;
			}
		}
		if (!fit)
			puts("Item does not fit.");	
		else
			printf("%li\n",best);
	}
}
