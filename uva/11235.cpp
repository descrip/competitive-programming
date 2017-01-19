#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAX = 10e+5;

int n, q;
int arr[MAX], freq[MAX];
pair<int,int> tree[(int)(ceil(log2(MAX))+1)];

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r) tree[n] = arr[l];
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> n;
		if (n == 0) break;
		cin >> q;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		freq[0] = 1;
		for (int i = 1; i < n; ++i)
			if (arr[i] == arr[i-1]) ++freq[i];
			else freq[i] = 0;
		
	}
return 0;}
