#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	long long n, A; cin >> n >> A;
	vector<long long> d(n);
	long long tot = 0;
	for (int i = 0; i < n; ++i){
		cin >> d[i];
		tot += d[i];
	}
	for (int i = 0; i < n; ++i)
		cout << d[i] - (min(A-n+1,d[i]) - max(1LL,A-tot+d[i]) + 1) << ' ';
return 0;}
