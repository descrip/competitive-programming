#include <bits/stdc++.h>
using namespace std;

int main(){
	//cin.sync_with_stdio(0); cin.tie(0);
	long long c, hr, hb, wr, wb;
	cin >> c >> hr >> hb >> wr >> wb;
	if ((long double) hr / wr < (long double) hb / wb){
		swap(hr,hb);
		swap(wr,wb);
	}
	if ((long double) hr / wr == (long double) hb / wb){
		if (wr <= wb) wb = c+1;
		else{
			swap(wr,wb);
			wb = c+1;
		}
	}
	long long rcnt = c / wr, curr = 0, ans = 0;
	long double actcurr = 0, actans = 0;
	while (rcnt >= 0){
		curr = hr * rcnt + ((c - rcnt * wr) / wb) * hb;
		actcurr = hr * rcnt + ((long double)(c - rcnt * wr) / wb) * hb;
		//cout << actcurr << ' ' << actans << '\n';
		//cout << rcnt << ' ' <<(c - rcnt * wr) * hb / wb << '\n';
		/*
		if (curr < ans) break;
		else if (curr > ans){ 
			ans = curr;
			cout << rcnt << ' ' << hr * rcnt << ' ' << ((c - rcnt * wr) / wb) * hb << '\n';
		}
		*/
		if (actcurr < actans){
			ans = max(ans,curr);
			break;
		}
		else{
			ans = max(ans,curr);
			actans = actcurr;
		}
		--rcnt;
	}
	cout << ans << '\n';
return 0;}
