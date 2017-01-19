#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

map<string,int> n2i;
int lastid = 0;
vector<int> pset, setsize, setrank;
void init(int n){
	pset = vector<int> (2*n+1);
	setsize = vector<int> (2*n+1,1);
	setrank = vector<int> (2*n+1,0);
	for (int i = 0; i < 2*n+1; ++i) pset[i] = i;
}
int findset(int a){return (pset[a] == a) ? a : (pset[a] = findset(pset[a]));}
bool sameset(int a, int b){return findset(a) == findset(b);}
void unionset(int a, int b){
	if (sameset(a,b)) return;
	int x = findset(a), y = findset(b);
	if (setrank[x] > setrank[y]){
		pset[y] = x;
		setsize[x] += setsize[y];
	}
	else{
		pset[x] = y;
		setsize[y] += setsize[x];
		if (setrank[x] == setrank[y]) ++setrank[y];
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int test = 0; test < t; ++test){
		int f; cin >> f;
		init(f);
		for (int i = 0; i < f; ++i){
			string s, t; cin >> s >> t;
			if (n2i.count(s) == 0) n2i[s] = lastid++;
			if (n2i.count(t) == 0) n2i[t] = lastid++;
			unionset(n2i[s],n2i[t]);
			cout << setsize[findset(n2i[t])] << '\n';
		}
	}
return 0;}
