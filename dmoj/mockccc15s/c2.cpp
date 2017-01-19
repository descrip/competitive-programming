#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int n;
	vector<pair<int,int>> v (n);
	scan(n);
	for (int i = 0; i < n; ++i){
		scan(p[i].first);
		scan(p[i].second);
	}
	sort(p.begin(),p.end());
	vector<bool> used (n);
	int left = 0;
	for (int i = 1; i < n; ++i)
		if (p[i].first < p[left].first)
			left = i;
	int start = left;
	do {
		int m = -1;
		int dist = 0xFFFFFFF;
		for (int i = 0; i < n; ++i){
			if (i == left)
				continue;
			if (
		}
	}
}
