#include <cstdio>
using namespace std;

#define pb push_back
#define gcd __gcd
typedef long long ll;

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; i+=2){
		for (int j = 0; j < (n - i) / 2; ++j)
			printf("*");
		for (int j = 0; j < i; ++j)
			printf("D");
		for (int j = 0; j < (n - i) / 2; ++j)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < n; ++i)
		printf("D");
	printf("\n");
	for (int i = n - 2; i >= 1; i-=2){
		for (int j = 0; j < (n - i) / 2; ++j)
			printf("*");
		for (int j = 0; j < i; ++j)
			printf("D");
		for (int j = 0; j < (n - i) / 2; ++j)
			printf("*");
		printf("\n");
	}
	return 0;
}
