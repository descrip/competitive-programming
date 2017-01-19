#include <vector>
#include <iostream>
using namespace std;

const int SLP = 1, WAIT = 2, MAX = 1001;

struct dog{
	int stat = SLP, time = 0, cnt = 0;
};

int D, T, F, W[MAX];
dog dogs[MAX];
vector<int> adj[MAX];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> D;
	for (int i = 1; i <= D; ++i)
		cin >> W[i];
	cin >> F;
	for (int i = 0; i < F; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	cin >> T;
	dogs[1].stat = WAIT;
	for (int t = 0; t <= T; ++t){
		for (int d = 1; d <= D; ++d){
			if (dogs[d].stat == WAIT && dogs[d].time == 0){
				for (int i = 0; i < adj[d].size(); ++i){
					dogs[adj[d][i]].time = W[adj[d][i]]-1;
					dogs[adj[d][i]].stat = WAIT;
				}
				dogs[d].stat = SLP;
				++dogs[d].cnt;
			}
			else if (dogs[d].stat == WAIT) --dogs[d].time;
		}
	}
	for (int i = 1; i <= D; ++i)
		cout << dogs[i].cnt << '\n';
	return 0;
return 0;}
