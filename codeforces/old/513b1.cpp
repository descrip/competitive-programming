#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int f(const vector<int> &v){
	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i; j < v.size(); ++j){
			int best = 999;
			for (int k = i; k <= j; ++k){
				best = min(best,v[k]);
			}
			ans += best;
		}
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<vector<int>> perm;
	vector<int> st;
	for (int i = 1; i <= n; ++i)
		st.pb(i);
	do{
		perm.pb(st);
	} while (next_permutation(st.begin(),st.end()));
	int best = 0, cnt = 0, temp;
	vector<int> ans;
	for (int i = 0; i < perm.size(); ++i){
		temp = f(perm[i]);
		if (temp > best){
			best = temp;
			cnt = 0;
		}
		if (temp == best){
			++cnt;
			if (cnt == m)
				ans = perm[i];
		}
	}
	for (int i = 0; i < ans.size(); ++i){
		printf("%d",ans[i]);
		if (i == ans.size() - 1)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}
