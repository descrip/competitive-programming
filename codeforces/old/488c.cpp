#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int hy, ay, dy, hm, am, dm, hb, ab, db;
	cin >> hy >> ay >> dy >> hm >> am >> dm >> hb >> ab >> db;
	int ans = 0xfffffff;
	for (int i = max(ay,dm+1); i <= 200; ++i)
		for (int j = dy; j <= 200; ++j){
			int t = ceil((double)hm/(i-dm));
			ans = min(ans, ab*(i-ay) + db*(j-dy) + max((am-j)*t+1-hy,0)*hb);
		}
	cout << ans << '\n';
return 0;}
