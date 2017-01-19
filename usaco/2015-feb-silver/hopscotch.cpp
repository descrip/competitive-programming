#include <fstream>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("hopscotch.in");
	int R, C, K; fin >> R >> C >> K;
	static int A[100][100], dp[100][100];
	for (int y = 0; y < R; ++y)
		for (int x = 0; x < C; ++x)
			fin >> A[y][x];
	dp[0][0] = 1;
	for (int y = 0; y < R; ++y)
		for (int x = 0; x < C; ++x)
			for (int y1 = y+1; y1 < R; ++y1)
				for (int x1 = x+1; x1 < C; ++x1)
					if (A[y][x] != A[y1][x1])
						dp[y1][x1] = (dp[y1][x1] + dp[y][x]) % 1000000007;
	ofstream fout ("hopscotch.out");
	fout << dp[R-1][C-1] << '\n';
	fin.close(); fout.close();
return 0;}
