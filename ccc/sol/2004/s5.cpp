#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int UP = 1, DOWN = 2;
int m, n, dp[100][100][3];

void process(int x, int y, int w){
	if (dp[y][x][w] == -1 || dp[y][x][0] == -1)
		return;
	
	if (w == UP){
		if (y != m - 1 && dp[y+1][x][0] != -1 && dp[y+1][x][w] != -1)
			dp[y][x][w] = max(dp[y][x][w], dp[y+1][x][w] + dp[y][x][0]);
		else if (y != m - 1)
			dp[y][x][w] = -1;
	}
	else if (w == DOWN){
		if (y != 0 && dp[y-1][x][0] != -1 && dp[y-1][x][w] != -1)
			dp[y][x][w] = max(dp[y][x][w], dp[y-1][x][w] + dp[y][x][0]);
		else if (y != m - 1)
			dp[y][x][w] = -1;
	}
	
	if (x > 0 && dp[y][x-1][0] != -1 && dp[y][x-1][UP] != -1)
		dp[y][x][w] = max(dp[y][x][w], dp[y][x-1][UP] + dp[y][x][0]);

	if (x > 0 && dp[y][x-1][0] != -1 && dp[y][x-1][DOWN] != -1)
		dp[y][x][w] = max(dp[y][x][w], dp[y][x-1][DOWN] + dp[y][x][0]);
}

int main(){
	while (true){
		memset(dp,0,sizeof(dp));
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
			break;
		char buff;
		for (int y = 0; y < m; y++)
			for (int x = 0; x < n; x++){
				scanf(" %c",&buff);
				if (buff == '*')
					dp[y][x][0] = -1;
				else if (buff == '.')
					dp[y][x][0] = 0;
				else
					dp[y][x][0] = buff - '0';
			}
		
		dp[m-1][0][1] = dp[m-1][0][2] = dp[m-1][0][0];
		for (int y = m - 2; y >= 0; y--)
			process(0,y,UP);

		for (int x = 1; x < n; x++){
			for (int y = m - 1; y >= 0; y--)
				process(x,y,UP);
			for (int y = 0; y < m; y++)
				process(x,y,DOWN);
		}

		/*
		for (int y = 0; y < m; y++){
			for (int x = 0; x < n; x++)
				printf("%02d ",dp[y][x][0]);
			printf("\n");
		}
		printf("\n");
		for (int y = 0; y < m; y++){
			for (int x = 0; x < n; x++)
				printf("%02d ",dp[y][x][1]);
			printf("\n");
		}
		printf("\n");
		for (int y = 0; y < m; y++){
			for (int x = 0; x < n; x++)
				printf("%02d ",dp[y][x][2]);
			printf("\n");
		}
		*/

		printf("%d\n",max(dp[m-1][n-1][1],dp[m-1][n-1][2]));
	}
	return 0;
}
