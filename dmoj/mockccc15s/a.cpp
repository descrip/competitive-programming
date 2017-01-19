#include <cstdlib>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int p, u, r1, r2;
	scanf("%d %d %d %d",&p,&u,&r1,&r2);
	vector<int> possval = {-1,1,2};
	set<vector<int>> ans;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if (i != j){
				for (int k = 1; k <= 1000; ++k){
					if (r1 *k + r2 *k > u)
						break;
					int score = possval[i] * r1 * k + possval[j] * r2 * k;
					vector<int> curr (3);
					curr[i] = r1 * k;
					curr[j] = r2 * k;
					int other = possval[3-i-j];
					if ((p-score) % other != 0)
						continue;
					if ((p-score) / other == u - r1*k - r2*k){
						curr[3-i-j] = (p-score) / other;
						ans.insert(curr);
					}
				}
			}
		}
	}
	/*
	for (auto i : ans){
		for (int j : i)
			printf("%d ",j);
		printf("\n");
	}
	*/
	printf("%d\n",ans.size());
	return 0;
}
