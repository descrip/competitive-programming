#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static int A[5000];
	static pair<int,pair<int,int> > dp[5000][5000];
	for (int i = 0; i < N; ++i){
		cin >> A[i];
		dp[i][1] = make_pair(1,make_pair(i,1));
	}
	for (int l = 0; l < 5000; ++l){
		for (int a = 2; a < 5000; ++a){
			dp[l][a] = min(
				min(),
		}
	}
return 0;}
