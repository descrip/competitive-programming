#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	ll r,c;
	while (true){
		scan(r);
		if (r == 0)
			break;
		c = 0;
		for (ll y = r; y > 0; --y)
			for (ll x = -r; x < 0; ++x)
				if (x*x + y*y <= r*r)
					break;
				else
					++c;
		printf("%lld\n",(ll)(2*r+1)*(2*r+1)-c*4);
	}
	return 0;
}
