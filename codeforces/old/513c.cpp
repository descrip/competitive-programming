#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int n;
	scan(n);
	vector<pair<int,int>> v (n);
	for (int i = 0; i < n; ++i){
		scan(v[i].first);
		scan(v[i].second);
	}
	double prob = 0.0;
	for (int i = 1; i <= 10; ++i){
		for (int k = 0; k < n; ++k){
			if (i <= v[k].second){
				double curr = 0.0;
				for (int j = 0; j < n; ++j){
					if (j != k && v[j].first <= i && i <= v[j].second){
						curr += 1.0/(v[j].second-v[j].first+1);
					}
					else if (i < v[j].first){
						curr = 0;
						break;
					}
				}
				printf("%d %d %f\n",i,k,curr);
				prob += curr * i;
			}
		}
	}
	printf("%f\n",prob);
}
