#include <bits/stdc++.h>
using namespace std;

bool valid(int a[]){
	if (a[0]+a[1] > a[2] && a[1]+a[2] > a[0] && a[0]+a[2] > a[1])
		return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int a[3]; int l;
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	cin >> l;
	sort(a,a+3);
	long long ans = 0;

	set<pair<int,int>> s2;
	vector<pair<int,int>> v2;
	for (int i = 0; i < 3; ++i)
		for (int j = i+1; j < 3; ++j)
			if (s2.count(make_pair(min(a[i],a[j]),max(a[i],a[j]))) == 0){
				s2.insert(make_pair(min(i,j),max(i,j)));
				v2.push_back(make_pair(min(a[i],a[j]),max(a[i],a[j])));
			}
	
	for (int i = 1; i <= l; ++i){
		int last = -1;
		for (int j = 0; j < 3; ++j){
			if (a[j] == last)
				continue;
			a[j] += i;
			ans += valid(a);
			a[j] -= i;
			last = a[j];
		}
		for (auto p : v2){
			
		}
	}
return 0;}
