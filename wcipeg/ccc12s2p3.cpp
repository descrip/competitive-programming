#include <iostream>
using namespace std;

struct node{
	char c;
	node& dir;
	vector<node&> exp;
}

int V, T, R1, R2, W;
vector<char> var, term;
map<char,vector<pair<char,char>>> exp;
map<char,vector<char>> qui;


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> V >> T;
	for (int i = 0; i < V; ++i) cin >> var[i];
	for (int i = 0; i < T; ++i) cin >> term[i];
	cin >> R1;
	for (int i = 0; i < R1; ++i){
		char a, b; cin >> a >> b;
		qui[a].push_back(b);
	}
	cin >> R2;
	for (int i = 0; i < R2; ++i){
		char a, b, c; cin >> a >> b >> c;
		exp[a].push_back({b,c});
	}
	cin >> W;
return 0;}
