#include <algorithm>
#include <vector>
#include <utility>
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
	
	vector<pair<int,int>> points (n+1);
	points[0] = {0,0};
	for (int i = 1; i <= n; ++i)
		scanf("%d %d",&points[i].first,&points[i].second);

	vector<pair<int,pair<int,int>>> pairs;
	for (int i = 0; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
			pairs.pb({(points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second), {i,j}});
	sort(pairs.begin(),pairs.end());

	vector<int> best(n+1), lastdist(n+1);
	for (auto p : pairs){
		int d = p.first, a = p.second.first, b = p.second.second;
		printf("%d %d %d\n",d,a,b);
		bool up = false;
		if (a != 0 && d > lastdist[b] && best[a]+1 > best[b]){
			best[b] = best[a]+1;
			lastdist[b] = d;
			up = true;
		}
		if (b != 0 && d > lastdist[a] && up == true ? best[b] : best[b]+1 > best[a]){
			if (up)
				best[a] = best[b];
			else
				best[a] = best[b]+1;
			best[a] = best[b];
			lastdist[a] = d;
		}
		for (int i : best)
			printf("%d ",i);
		printf("\n");
	}

	for (int i : best)
		printf("%d ",i);
	printf("\n");
	printf("%d\n",best[0]);
	return 0;
}
