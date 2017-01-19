#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<vector<int>> tall (n+1,vector<int>());
	for (int i = 0; i < m; ++i){
		int x, y;
		scanf("%d %d",&x,&y);
		tall[x].pb(y);
	}
	int p, q;
	scanf("%d %d",&p,&q);
	queue<int> qu;
	qu.push(p);
	while (!qu.empty()){
		if (qu.front() == q){
			puts("yes");
			return 0;
		}
		for (int i : tall[qu.front()])
			qu.push(i);
		qu.pop();
	}
	qu.push(q);
	while (!qu.empty()){
		if (qu.front() == p){
			puts("no");
			return 0;
		}
		for (int i : tall[qu.front()])
			qu.push(i);
		qu.pop();
	}
	puts("unknown");
	return 0;
}
