#include <iostream>
using namespace std;

long long ans = 0;

void recur(int a, int n, int s){
	if (s == 3){
		//ans += n - a;
		ans++;
		return;
	}
	for (int i = a + 1; i <= n - 1; i++)
		recur(i,n,s+1);
}

int main(){
	int J;
	cin >> J;
	recur(0,J,0);
	cout << ans << endl;
	return 0;
}
