#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, T, t[5000];
	cin >> n >> T;
	double dp[5000][5000], p[5000];

	for (int i = 0; i < n; i++){
		cin >> p[i] >> t[i];
		p[i] /= 100;
	}
	
	return 0;	
}
