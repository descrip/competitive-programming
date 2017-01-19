#include <vector>
#include <set>
#include <cstdio>
using namespace std;

#define pb insert_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int r, l;
	scanf("%d %d",&r,&l);
	vector<vector<bool>> lights (r, vector<bool> (l));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < l; ++j){
			int a;
			scanf("%d",&a);
			lights[i][j] = (a == 1 ? true : false);
		}
	set<vector<bool>> level, next;
	level.insert(lights[0]);
	for (int i = 1; i < r; ++i){
		for (auto j : level){
			for (int k = 0; k < l; ++k){
				j[k] = j[k] ^ lights[i][k];
			}
			next.insert(j);
		}
		next.insert(lights[i]);
		level = move(next);
	}
	printf("%d\n",level.size());
	return 0;
}
