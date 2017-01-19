#include <utility>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

void add(int x, int y, vector<set<int>> &fr){
	if (fr[x].count(y) == 0){
		fr[x].insert(y);
		fr[y].insert(x);
	}
}

int main(){
	vector<set<int>> fr (50, set<int>());
	add(1,6,fr);
	add(2,6,fr);
	add(3,4,fr);
	add(3,5,fr);
	add(3,6,fr);
	add(3,15,fr);
	add(4,5,fr);
	add(4,6,fr);
	add(5,6,fr);
	add(6,7,fr);
	add(7,8,fr);
	add(8,9,fr);
	add(9,10,fr);
	add(9,12,fr);
	add(10,11,fr);
	add(11,12,fr);
	add(12,13,fr);
	add(13,14,fr);
	add(13,15,fr);
	//love triangle
	add(16,17,fr);
	add(16,18,fr);
	add(17,18,fr);
	while (true){
		char com;
		int x, y;
		scanf("%c",&com);
		if (com == 'i'){
			scanf("%d %d",&x,&y);
			add(x,y,fr);
		}
		else if (com == 'd'){
			scanf("%d %d",&x,&y);
			if (fr[x].count(y) == 1){
				fr[x].erase(y);
				fr[y].erase(x);
			}
		}
		else if (com == 'n'){
			scanf("%d",&x);
			printf("%d\n",fr[x].size());
		}
		else if (com == 'f'){
			scanf("%d",&x);
			set<int> fof;
			for (int i : fr[x])
				for (int j : fr[i])
					fof.insert(j);
			for (int i : fr[x])
				fof.erase(i);
			fof.erase(x);
			printf("%d\n",fof.size());
		}
		else if (com == 's'){
			scanf("%d %d",&x,&y);
			queue<pair<int,int>> q;
			q.push(make_pair(x,0));
			vector<bool> vis (50,false);
			vis[x] = true;
			while (!q.empty()){
				if (q.front().first == y){
					printf("%d\n",q.front().second);
					break;
				}
				for (int i : fr[q.front().first])
					if (!vis[i]){
						q.push(make_pair(i,q.front().second+1));
						vis[i] = true;
					}
				q.pop();
			}
			if (q.empty())
				puts("Not connected");
		}
		else if (com == 'q')
			break;
	}
	return 0;
}
