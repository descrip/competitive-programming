//this was the actual divine punishment.
//should have done frequency analysis? idk, i brute forced.
//the keyword is "god"

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v;
	int a;
	while (cin >> a)
		v.push_back(a);
	for (int i = 97; i <= 97+26; ++i)
		for (int j = 97; j <= 97+26; ++j)
			for (int k = 97; k <= 97+26; ++k){
				string s = "";
				long long ans = 0;
				for (int l = 0; l < v.size(); ++l)
					if (l % 3 == 0){
						s += (char)(v[l] ^ i);
						ans += v[l] ^ i;
					}
					else if (l % 3 == 1){
						s += (char)(v[l] ^ j);
						ans += v[l] ^ j;
					}
					else if (l % 3 == 2){
						s += (char)(v[l] ^ k);
						ans += v[l] ^ k;
					}

				/*
				original search
				if (s.find("the") != string::npos && s.find("be") != string::npos && s.find("and") != string::npos)
					cout << i << ' ' << j << ' ' << k << ' ' << s << ' ' << ans << '\n';
				*/

				//finding god
				if (s.find("God") != string::npos && s.find("He") != string::npos && s.find("Father") != string::npos)
					cout << ans << '\n';
			}
return 0;}

