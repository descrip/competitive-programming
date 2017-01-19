#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int t;
	scan(t);
	vector<int> scores;
	ll tot = 0;
	for (int i = 0; i < t; ++i){
		int curr;
		scan(curr);
		auto it = upper_bound(scores.begin(),scores.end(),curr);
		tot += i - (it - scores.begin()) + 1;
		scores.insert(it,curr);
	}
	printf("%.2f\n",tot / (double) t);
	return 0;
}
