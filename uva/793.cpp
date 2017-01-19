#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector<int> pset, setsize, setrank;
void init(int n){
	pset = vector<int> (n+1);
	setsize = vector<int> (n+1,1);
	setrank = vector<int> (n+1,0);
	for (int i = 1; i <= n; ++i) pset[i] = i;
}
int findset(int a){
	return (pset[a] == a) ? a : (pset[a] = findset(pset[a]));
}
bool sameset(int a, int b){
	return findset(a) == findset(b);
}
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
		int n; cin >> n;
		init(n);
		char type; int ci, cj;
		int no = 0, yes = 0;
		cin.ignore(256,'\n');
		while (true){
			string s; getline(cin,s);
			if (s == "") break;
			istringstream iss (s);
			iss >> type >> ci >> cj;
			if (type == 'c') unionset(ci,cj);
			else if (sameset(ci,cj)) ++yes;
			else ++no;
		}
		cout << yes << ',' << no << '\n';
		if (test != t-1) cout << '\n';
	}
return 0;}
