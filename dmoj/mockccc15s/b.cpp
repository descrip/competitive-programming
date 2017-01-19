#include <set>
#include <vector>
#include <algorithm>
#include <functional>
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
	vector<int> d (n);
	for (int i = 0; i < n; ++i)
		scan(d[i]);
	sort(d.begin(),d.end(),greater<int>());
	multiset<int> c;
	c.insert(d[0]);
	for (int i = 1; i < d.size(); ++i){
		auto it = c.upper_bound(d[i]);
		if (it == c.end())
			c.insert(d[i]);
		else{
			c.erase(it);
			c.insert(d[i]);
		}
	}
	printf("%d\n",c.size());
	return 0;
}
