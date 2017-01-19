#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define pb push_back
typedef long long ll;

int rquery(const vector<vector<pair<int,int>>> &v, int a, int b, int c, vector<bool> &vis){
	if (a == b)
		return 1;
	int cnt = 0;
	for (int i = 0; i < v[a].size(); ++i)
		if (vis[v[a][i].first] == false && v[a][i].second == c){
			//printf("%d %d %d %d\n",1,a,v[a][i].first,v[a][i].second);
			vis[v[a][i].first] = true;
			cnt += rquery(v,v[a][i].first,b,c,vis);
			vis[v[a][i].first] = false;
		}
	return cnt;
}

int query(const vector<vector<pair<int,int>>> &v, int a, int b, vector<bool> &vis){
	int cnt = 0;
	vis[a] = true;
	vector<int> disC;
	int temp;
	for (int i = 0; i < v[a].size(); ++i){
		if (find(disC.begin(),disC.end(),v[a][i].second) == disC.end()){
			vis[v[a][i].first] = true;
			//printf("%d %d %d %d\n",0,a,v[a][i].first,v[a][i].second);
			temp = rquery(v,v[a][i].first,b,v[a][i].second,vis);
			vis[v[a][i].first] = false;
			if (temp != 0){
				cnt += temp;
				disC.pb(v[a][i].second);
			}
		}
	}
	return disC.size();
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<vector<pair<int,int>>> paths (n+1,vector<pair<int,int>>());
	for (int i = 0; i < m; ++i){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		if (a != b){
			paths[a].pb(make_pair(b,c));
			paths[b].pb(make_pair(a,c));
		}
	}
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; ++i){
		int a, b;
		scanf("%d %d",&a,&b);
		vector<bool> vis (n+1,false);
		printf("%d\n",query(paths,a,b,vis));
	}
	return 0;
}
