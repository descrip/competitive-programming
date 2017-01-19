#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for (int n = 0; n < N; ++n){
		string s; cin >> s;
		if (s.size() == 1){
			if (s == "9")
				cout << "11\n";
			else
				cout << (char)(s[0]+1) << '\n';
		}
		else if (s.size()%2 == 0){
			string s1 = s.substr(0, s.size()/2), s2 = s1;
			reverse(s2.begin(), s2.end());
			bool ok = true;
			for (int i = 0; i < s2.size(); ++i)
				if (s2[i] == s[s.size()/2+i]){
					if (i == s2.size()-1)
						ok = false;
					continue;
				}
				else{
					if (s2[i] < s[s.size()/2+i])
						ok = false;
					break;
				}
			if (ok){
				cout << s1 << s2 << '\n';
				continue;
			}
			bool eno = false;
			for (int i = s1.size()-1; i >= 0; --i)
				if (s1[i] == '9'){
					s1[i] = '0';
					if (i == 0){
						s1.insert(0, "1");
						eno = true;
						break;
					}
				}
				else{
					++s1[i];
					break;
				}
			s2 = s1;
			reverse(s2.begin(), s2.end());
			if (eno)
				s2 = s2.substr(1);
			cout << s1 << s2 << '\n';
		}
		else{
			string s1 = s.substr(0, s.size()/2+1), s22 = s1.substr(0, s.size()/2);
			reverse(s22.begin(), s22.end());
			bool ok = true;
			for (int i = 0; i < s22.size(); ++i)
				if (s22[i] == s[s.size()/2+1+i]){
					if (i == s22.size()-1)
						ok = false;
					continue;
				}
				else{
					if (s22[i] < s[s.size()/2+1+i])
						ok = false;
					break;
				}
			if (ok){
				cout << s1 << s22 << '\n';
				continue;
			}
			bool eno = false;
			for (int i = s1.size()-1; i >= 0; --i)
				if (s1[i] == '9'){
					s1[i] = '0';
					if (i == 0){
						s1.insert(0, "1");
						eno = true;
						break;
					}
				}
				else{
					++s1[i];
					break;
				}
			if (eno){
				s1 = s1.substr(0, s1.size()-1);
				s22 = s1;
			}
			else
				s22 = s1.substr(0, s.size()/2);
			reverse(s22.begin(), s22.end());
			cout << s1 << s22 << '\n';
		}
	}
return 0;}

