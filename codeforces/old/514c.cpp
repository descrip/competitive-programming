#include <set>
#include <iostream>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	set<string> v;
	string s;
	for (int i = 0; i < n; ++i){
		cin >> s;
		for (int j = 0; j < s.length(); ++j)
			for (int k = 0; k < 3; ++k){
				if (97+k == s[j]) continue;
				char prev = s[j];
				s[j] = 97+k;
				v.insert(s);
				s[j] = prev;
			}
	}
	for (int i = 0; i < m; ++i){
		cin >> s;
		if (v.count(s) > 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
