#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	multiset<int,greater<int>> s;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		s.insert(a);
	}
	int wid = 0, hei = 0;
	for (auto it = s.begin(); it != s.end(); ++it){
		if (s.count(*it) >= 2){
			wid = *it;
			s.erase(it);
			s.erase(s.find(wid));
			break;
		}
		else if (s.count((*it)-1) >= 1){
			wid = (*it)-1;
			s.erase(it);
			s.erase(s.find(wid));
			break;
		}
	}
	for (auto it = s.begin(); it != s.end(); ++it){
		if (s.count(*it) >= 2){
			hei = *it;
			s.erase(it);
			s.erase(s.find(hei));
			break;
		}
		else if (s.count((*it)-1) >= 1){
			hei = (*it)-1;
			s.erase(it);
			s.erase(s.find(hei));
			break;
		}
	}
	cout << (unsigned long long) wid * hei << '\n';
return 0;}
