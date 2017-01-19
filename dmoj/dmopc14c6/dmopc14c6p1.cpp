#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string last = "", curr;
	for (int i = 0; i < n; ++i){
		getline(cin,curr);
		if (curr == "Bessarion"){
			getline(cin,curr);
			if ((curr == "Leslie" && last == "Bayview") || (curr == "Bayview" && last == "Leslie")){
				cout << "Y\n";
				return 0;
			}
		}
		else last = curr;
	}
	cout << "N\n";
return 0;}
