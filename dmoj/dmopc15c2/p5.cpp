#include <bits/stdc++.h>
using namespace std;

struct line{
	int m, s, id;
} li[100005], sta[100005];
bool operator<(const line &a, const line &b){
	return (a.m < b.m) || (a.m == b.m && a.s < b.s);
}
int ans[500005];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, Q; cin >> N >> Q;
	for (int i = 0; i < N; ++i){
		cin >> li[i].s >> li[i].m;
		li[i].id = i;
	}
	sort(li, li+N);

	int curr = -1;
	for (int i = 0; i < N; ++i){
		while ((curr >= 0 && sta[curr].m == li[i].m) ||
			(curr >= 1 && 1LL*(sta[curr-1].s - li[i].s)*(sta[curr].m - sta[curr-1].m) < 1LL*(sta[curr-1].s - sta[curr].s)*(li[i].m - sta[curr-1].m)))
			--curr;
		sta[++curr] = li[i];
	}

	int cnt = 0;
	fill_n(ans, 500005, 0xfffffff);
	for (int i = 0; i <= 500000;){
		if (cnt == curr){
			ans[i] = min(ans[i], sta[cnt].id);
			++i;
			continue;
		}
		long long y1 = 1LL * sta[cnt].m * i + sta[cnt].s,
			 	  y2 = 1LL * sta[cnt+1].m * i + sta[cnt+1].s;
		if (y2 < y1){
			ans[i] = min(ans[i], sta[cnt].id);
			++i;
		}
		else if (y1 == y2){
			ans[i] = min(ans[i], min(sta[cnt].id, sta[cnt+1].id));
			++cnt;
		}
		else
			++cnt;
	}

	for (int q = 0; q < Q; ++q){
		int x; cin >> x;
		cout << ans[x] << '\n';
	}
return 0;}

