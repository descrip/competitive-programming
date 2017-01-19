#include <map>
#include <iostream>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int n;
	cin >> n;
	map<string,string> dict;
	for (int i = 0; i < n; ++i){
		string a, b;
		cin >> a >> b;
		dict[b] = a;
	}
	string piece, full;
	cin >> full;
	for (int i = 0; i < full.length(); ++i){
		piece += full[i];
		if (dict.count(piece) != 0){
			cout << dict[piece];
			piece = "";
		}
	}
	cout << '\n';
	return 0;
}
