#include <bits/stdc++.h>
using namespace std;

struct event{
	char c; int x, r;
	event(char a, int b, int d): c(a), x(b), r(d) {}
};

const int MAXN = (1e6)+5, MAXR = (1e8)+5;
int N, A[MAXN], id2R[MAXN], R2id[MAXN];
vector<int> allR;
vector<event> E;

int sum(int i){
	int ret = 0;
	while (i > 0){
		ret += A[i];
		i -= (i & -i);
	}
	return ret;
}

void add(int i, int k){
	while (i < MAXN){
		A[i] += k;
		i += (i & -i);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		char c; int a, b = -1; cin >> c;
		if (c == 'Q')
			cin >> a;
		else
			cin >> a >> b;
		E.push_back(event(c, a, b));
		if (b != -1)
			allR.push_back(b);
	}
	allR.push_back(0);
	sort(allR.begin(), allR.end());
	int cnt = 0;
	for (event e : E){
		if (e.c == 'N'){
			int it = lower_bound(allR.begin(), allR.end(), e.r) - allR.begin();
			add(it, 1);
			id2R[e.x] = it;
			R2id[it] = e.x;
			++cnt;
		}
		else if (e.c == 'M'){
			int oldR = id2R[e.x];
			int it = lower_bound(allR.begin(), allR.end(), e.r) - allR.begin();
			add(oldR, -1);
			add(it, 1);
			id2R[e.x] = it;
			R2id[oldR] = 0;
			R2id[it] = e.x;
		}
		else if (e.c == 'Q'){
			int lo = 1, hi = allR.size()-1, mid;
			while (lo < hi){
				mid = lo + (hi - lo)/2;
				if (sum(mid) < cnt-e.x+1)
					lo = mid+1;
				else
					hi = mid;
			}
			cout << R2id[lo] << '\n';
			//cout << lo << ' ' << hi << ' ' << allR[lo] << ' ' << R2id[lo] << '\n';
		}
		/*
		for (int i = 0; i < allR.size(); ++i)
			cout << R2id[i] << ' ';
		cout << '\n';
		*/
	}
	//cout << sum(4) << ' ' << cnt << '\n';
return 0;}

