#include <set>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int t;
	scan(t);
	vector<char> vaccept {'A','B','C','E','G','L','O','R'};
	set<char> accept (vaccept.begin(), vaccept.end());
	for (int test = 0; test < t; ++test){
		int n;
		scan(n);
		vector<char> bowls (n);
		vector<int> shift (n);
		for (int i = 0; i < n; ++i)
			scanf(" %c",&bowls[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d",&shift[i]);
		int i;
		for (i = 0; i < n; ++i)
			if (accept.count(bowls[i]) == 0)
				break;
		if (i == n){
			puts("0");
			continue;
		}
		for (i = 1; i < 999; ++i){
			for (int j = 0; j < n; ++j){
				bowls[j] = (char) ((bowls[j] - 65 + shift[j]) % 26 + 65);
				//printf("%c ",bowls[j]);
			}
			//printf("\n");
			int j;
			for (j = 0; j < n; ++j)
				if (accept.count(bowls[j]) == 0)
					break;
			if (j == n){
				printf("%d\n",i);
				break;
			}
		}
		if (i == 999)
			puts("-1");
	}
	return 0;
}
