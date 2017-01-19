#include <queue>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back
#define gcd __gcd
typedef long long ll;

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<vector<int>> paths (n+1, vector<int>());
	set<int> used;
	multiset<int> mused;
	for (int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d",&a,&b);
		paths[a].pb(b);
		used.insert(b);
		mused.insert(b);
	}
	queue<int> s;
	for (int i = 1; i <= n; ++i)
		if (used.find(i) == used.end())
			s.push(i);
	while (!s.empty()){
		while (!paths[s.front()].empty()){
			mused.erase(paths[s.front()][0]);
			if (mused.count(paths[s.front()][0]) == 1)
				s.push(paths[s.front()][0]);
			paths[s.front()].erase(paths[s.front()].begin());
		}
		s.pop();
	}
	if (!mused.empty())
		printf("%d\n",n);
	else
		printf("%d\n",n-1);
}
