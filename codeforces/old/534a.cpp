#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	if (n >= 4){
		cout << n << '\n';
		for (int i = 2; i <= n; i+=2)
			cout << i << ' ';
		for (int i = 1; i <= n; i+=2)
			cout << i << ' ';
	}
	else if (n == 3) cout << "2\n1 3\n";
	else cout << "1\n1";
return 0;}
