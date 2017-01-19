#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

bool lel(const vector<int> h, int l, int k){
	l *= 2;
	for (int start = 0; start < h.size(); ++start){
		int pos = start + 1, last = start, currk = k;
		for (; pos < start + h.size(); ++pos){
			if (abs((h[pos % h.size()] - h[last] + 500000) % 1000000 - 500000) > l){
				last = pos % h.size();
				--currk;
			}
		}
		if (currk > 0)
			return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d",&n);
	vector<int> h (n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&h[i]);
	int k;
	scanf("%d",&k);
	sort(h.begin(),h.end());
	int lo = 0, hi = 1000000, mid;
	while (lo <= hi){
		mid = lo + (hi - lo) / 2;
		if (!lel(h,mid,k))
			lo = mid+1;
		else
			hi = mid-1;
	}
	mid = lo + (hi - lo) / 2;
	printf("%d\n",mid);
	return 0;
}
