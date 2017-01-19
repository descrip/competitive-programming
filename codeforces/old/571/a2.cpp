#include <bits/stdc++.h>
using namespace std;

int valid(int a[]){
	if (a[0]+a[1] > a[2] && a[1]+a[2] > a[0] && a[0]+a[2] > a[1])
		return 1;
	else if (a[0]+a[1] >= a[2] && a[1]+a[2] >= a[0] && a[0]+a[2] >= a[1])
		return 2;
	else return 3;
}

bool ok = false;
int fin, mult;

long long recur(int a[], int l){
	if (valid(a) == 3 && ok)
		return 0;
	else if (l == fin){
		//cout << 'a' << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << l << ' ' << valid(a) << '\n';
		return (valid(a) == 1);
	}
	else{
		//cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << l << ' ' << valid(a) << '\n';
		long long ans = (valid(a) == 1);
		for (int i = 0; i < 3; ++i){
			a[i]++;
			if (a[0] <= a[1] && a[1] <= a[2]){
				if (l == fin-1)
					ans += recur(a,l+1);
				else
					ans += mult * recur(a,l+1);
			}
			a[i]--;
		}
		return ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int a[3]; int l;
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	cin >> l;
	fin = l;
	sort(a,a+3);

	if (a[0] == a[1] && a[1] == a[2])
		mult = 3;
	else if (a[0] == a[1] || a[2] == a[1])
		mult = 2;
	else 
		mult = 1;
	
	cout << recur(a,0) << '\n';
return 0;}
