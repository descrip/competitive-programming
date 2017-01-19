#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*
	a+b+c+d = 2b+2c
	a+d = b+c
	
	b+c = 2d-2a
	a+d = 2d-2a
	3a = d
	*/
	int n; cin >> n;
	vector<int> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(),v.end());
	if (n == 0){
		cout << "YES\n";
		cout << 1 << '\n' << 1 << '\n' << 3 << '\n' << 3 << '\n';
	}
	else if (n == 1){
		cout << "YES\n";
		cout << v[0] << '\n' << 3*v[0] << '\n' << 3*v[0] << '\n';
	}
	else if (n == 2){
		if (4*v[0] > v[1])
			cout << "YES\n" << 4*v[0]-v[1] << '\n' << v[0]*3 << '\n';
		else
			cout << "NO\n";
	}
	else if (n == 3){
		for (int i = 1; i <= 1000000; ++i){
			v.push_back(i);
			sort(v.begin(),v.end());
			if (v[0]+v[3] == v[1]+v[2] && v[0]*3 == v[3]){
				cout << "YES\n" << i << '\n';
				break;
			}
			else if (i == 1000000)
				cout << "NO\n";
			v.erase(find(v.begin(),v.end(),i));
		}
	}
	else{
		if (v[0]+v[3] == v[1]+v[2] && v[0]*3 == v[3])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
return 0;}
