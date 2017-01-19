#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int t;
	scan(t);
	for (int test = 0; test < t; ++test){
		int r, c;
		scan(r);
		scan(c);
		vector<vector<char>> grid (r+2, vector<char> (c+2));
		for (int y = 1; y <= r; ++y)
			for (int x = 1; x <= c; ++x)
				scanf(" %c",&grid[y][x]);
		vector<vector<int>> dp (r+2, vector<int> (c+2,-1));
		dp[1][1] = 1;
		queue<pair<int,int>> q;
		q.push({1,1});
		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (grid[y][x] == '*' || dp[y][x] == -1)
				continue;
			else if (grid[y][x] == '|'){
				if (dp[y+1][x] == -1){
					dp[y+1][x] = dp[y][x]+1;
					q.push({x,y+1});
				}
				if (dp[y-1][x] == -1){
					dp[y-1][x] = dp[y][x]+1;
					q.push({x,y-1});
				}
			}
			else if (grid[y][x] == '-'){
				if (dp[y][x+1] == -1){
					dp[y][x+1] = dp[y][x]+1;
					q.push({x+1,y});
				}
				if (dp[y][x-1] == -1){
					dp[y][x-1] = dp[y][x]+1;
					q.push({x-1,y});
				}
			}
			else if (grid[y][x] == '+'){
				if (dp[y+1][x] == -1){
					dp[y+1][x] = dp[y][x]+1;
					q.push({x,y+1});
				}
				if (dp[y-1][x] == -1){
					dp[y-1][x] = dp[y][x]+1;
					q.push({x,y-1});
				}if (dp[y][x+1] == -1){
					dp[y][x+1] = dp[y][x]+1;
					q.push({x+1,y});
				}
				if (dp[y][x-1] == -1){
					dp[y][x-1] = dp[y][x]+1;
					q.push({x-1,y});
				}
			}
		}
		if (grid[r][c] == '*')
			puts("-1");
		else
			printf("%d\n",dp[r][c]);
	}
}
