#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	for (int test = 0; test < 5; ++test){
		for (int num = 0; num < 5; ++num){
			string s; cin >> s;
			int sum = 0;
			for (int i = 0; i < s.size(); ++i)
				if (i % 2 == 0) sum += ((s[s.size()-i-1] - '0')*2) / 10 + ((s[s.size()-i-1] - '0')*2) % 10;
				else sum += s[s.size()-i-1] - '0';
			int ideal = (sum / 10 + 1) * 10;
			if (ideal - sum == 10) cout << 0;
			else cout << ideal - sum;
		}
		cout << '\n';
	}
return 0;}
