#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

bool onLine(int x0, int y0, int xs, int ys, int xt, int yt){
	if ((ys - y0)*(xt-x0) == (yt-y0)*(xs-x0))
		return true;
	return false;
}

int main(){
	int n, x0, y0;
	scanf("%d %d %d",&n,&x0,&y0);
	vector<pair<int,int>> s(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d",&s[i].first,&s[i].second);
	vector<bool> vis (n);
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		if (!vis[i]){
			++cnt;
			for (int j = i+1; j < n; ++j)
				if (onLine(x0,y0,s[i].first,s[i].second,s[j].first,s[j].second))
					vis[j] = true;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
