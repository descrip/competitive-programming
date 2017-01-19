#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int inver(const vector<int> &p){
	vector<int> q (p);
	int cnt = 0;
	while (true){
		for (int i = 0; i < p.size()-1; ++i){
			if (q[i] > q[i+1]){
				iter_swap(q.begin()+i,q.begin()+i+1);
				++cnt;
				break;
			}
			else if (i == p.size()-2)
				goto quit;
		}
	}
quit:
	return cnt;
}

double recur(vector<int> p, int k, double prob){
	if (k == 0){
		if (p.size() == 1)
			return 0;
		else
			return inver(p) * prob;
	}
	double tot = 0;
	for (int i = 0; i < p.size(); ++i){
		for (int j = i; j < p.size(); ++j){
			reverse(p.begin()+i,p.begin()+j+1);
			tot += recur(p,k-1,prob*(1.0/(p.size() * (p.size()-1))));
			reverse(p.begin()+i,p.begin()+j+1);
		}
	}
	return tot;
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	vector<int> p (n);
	for (int i = 0; i < n; ++i)
		scan(p[i]);
	printf("%.15f",recur(p,k,1.0));
	return 0;
}
