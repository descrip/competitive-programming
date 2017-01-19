#include <cstdio>
using namespace std;

bool isZero = false;

int recur(int m, int n){
	//printf("S: %d %d\n",m,n);
	if (m == 1){
		if (n == 0 || n == 4){
			isZero = true;
			return 0;
		}
		else if (n == 1 || n == 3)
			return 1;
		else if (n == 2)
			return 2;
	}
	int s = n / 5;
	int r = n - s * 5;
	//printf("%d %d\n",s,r);
	if (r == 0 || r == 4)
		return 0 + 5 * recur(m - 1, s);
	else if (r == 1 || r == 3)
		return 1 + 5 * recur(m - 1, s);
	else if (r == 2)
		return 2 + 5 * recur(m - 1, s);
}

int main(){
	int T, m, n, x, y;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d %d %d",&m,&x,&y);
		//printf("%d\n",recur(m,x));
		n = recur(m,x);
		if (isZero == true)
			puts("empty");
		else if (y < n)
			puts("crystal");
		else
			puts("empty");
		isZero = false;
	}
	return 0;
}
