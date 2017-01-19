/* Was stuck on this question for a while, got this great hash table idea.
 * But my idea it still times out. So I went and looked at the mmhs solution.
 * Apparently they looped to an arbitrary number of 50, and if they couldn't find it, they just printed -1.
 * So I'm going to put this question off for a while.
 */

#include <set>
#include <bitset>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int m, n, a, b, c;

int gton(const vector<vector<bool>> &v){
	bitset<20> bs;
	int pos = 0;
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j)
			bs.set(pos++, v[i][j]);
	return bs.to_ullong();
}

vector<vector<bool>> ntog(ull a){
	bitset<20> bs (a);
	int cnt = 19;
	vector<vector<bool>> v (n, vector<bool> (m));
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j)
			v[i][j] = bs[cnt--];
	return v;
}

int nei(const vector<vector<bool>> v, int x, int y){
	int cnt = 0;
	for (int i = max(y-1,0); i <= min(y+1,n-1); ++i)
		for (int j = max(x-1,0); j <= min(x+1,m-1); ++j)
			if ((x != j && y != i) && v[i][j])
				++cnt;
	return cnt;
}

void prog(vector<vector<bool>> &v){
	vector<pair<int,int>> kill, born;
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < m; ++x)
			if (v[x][y] && (nei(v,x,y) < a || nei(v,x,y) > b))
				kill.pb({x,y});
			else if (!v[x][y] && nei(v,x,y) > c)
				born.pb({x,y});
	for (auto i : kill)
		v[i.second][i.first] = false;
	for (auto i : born)
		v[i.second][i.first] = true;
}

int main(){
	scanf("%d %d %d %d %d",&m,&n,&a,&b,&c);
	vector<vector<bool>> query (n, vector<bool>(m));
	char buff;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			scanf("%c",&buff);
			query[i][j] = (buff == '.' ? false : true);
		}
	vector<short> ans (1 << (m*n), 9999);
	for (int i = 0; i < ans.size(); ++i){
		if (ans[i] == 9999){
			vector<vector<bool>> curr = ntog(i);
			vector<int> aff;
			set<int> prev;
			int cnt = 0;
			while (true){
				++cnt;
				prev.insert(gton(curr));
				prog(curr);
				int j = gton(curr);
				if (j == i || prev.count(gton(curr))){
					for (auto k : aff)
						ans[k] = 9999;
					break;
				}
				else{
					if (cnt < ans[j]){
						ans[j] = cnt;
						aff.pb(j);
					}
				}
				//printf("%d\n",i);
			}
		}
	}
	printf("%d\n",(ans[gton(query)] == 9999 ? 0 : ans[gton(query)]));
	return 0;
}
