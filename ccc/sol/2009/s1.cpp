#include <cmath>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	ll a, b;
	scanf("%lld %lld",&a,&b);
	int ans = 0;
	for (int i = 1; i < b; ++i){
		ll z = pow(i,6);
		if (a <= z && z <= b)
			++ans;
		else if (z > b)
			break;
	}
	printf("%d\n",ans);
	return 0;
}
