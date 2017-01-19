#include <utility>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

const int MAXN = 1000000;
int N, nbad;
set<int> C;
vector<int> V;
vector<pair<int,int>> bads;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		int a; cin >> a;
		C.insert(a);
	}
	{
		int a = 0, b = 1, c = 1, d = *C.rbegin();
		while (c <= *C.rbegin()){
			int k = (*C.rbegin() + b) / d;
			//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << '\n';
			int oldc = c, oldd = d;
			c = k*c - a; d = k*d - b;
			a = oldc; b = oldd;
			if ((b-a) % 2 == 1 && C.count(2*a*b) >= 1 && C.count(b*b-a*a)){
				bads.push_back({min(2*a*b,b*b-a*a),max(2*a*b,b*b-a*a)});
				V.push_back(2*a*b);
				V.push_back(b*b-a*a);
			}
		}
	}
	nbad = bads.size();
	for (auto i : bads)
		cout << i.first << ' ' << i.second << '\n';
return 0;}
