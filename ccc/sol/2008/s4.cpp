#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int recur(vector<int> v){
	if (v.size() == 1)
		return v[0];
	int best = 0, ans;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i+1; j < v.size(); ++j){
			int tempj = v[j], tempi = v[i];
			v.erase(v.begin() + j);

			v[i] = tempi + tempj;
			ans = recur(v);
			if (ans <= 24)
				best = max(best,ans);

			v[i] = tempi - tempj;
			ans = recur(v);
			if (ans <= 24)
				best = max(best,ans);

			v[i] = tempj - tempi;
			ans = recur(v);
			if (ans <= 24)
				best = max(best,ans);
			
			v[i] = tempi * tempj;
			ans = recur(v);
			if (ans <= 24)
				best = max(best,ans);
			
			if (tempj != 0 && tempi % tempj == 0){
				v[i] = tempi / tempj;
				ans = recur(v);
				if (ans <= 24)
					best = max(best,ans);
			}
			if (tempi != 0 && tempj % tempi == 0){
				v[i] = tempj / tempi;
				ans = recur(v);
				if (ans <= 24)
					best = max(best,ans);
			}

			v[i] = tempi;
			v.pb(tempj);
			sort(v.begin(),v.end());
		}
	/*
	printf("%d ",best);
	for (int i : v)
		printf("%d ",i);
	printf("\n");
	*/
	return best;
}

int main(){
	int t;
	scan(t);
	for (int test = 0; test < t; ++test){
		vector<int> cards (4);
		for (int i = 0; i < 4; ++i)
			scan(cards[i]);
		sort(cards.begin(),cards.end());
		printf("%d\n",recur(cards));
	}
	return 0;
}
