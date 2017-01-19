#include <bits/stdc++.h>
using namespace std;

#define dig(n) (int)floor(log10(n)+1)

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a;
	cout << "PERFECTION OUTPUT\n";
	vector<int> ans1;
	vector<string> ans2;
	while (cin >> a){
		if (a == 0)
			break;
		int ans = 0;
		for (int i = 1; i < a; ++i)
			if (a % i == 0)
				ans += i;
		ans1.push_back(a);
		if (a == ans)
			ans2.push_back("PERFECT");
		else if (ans < a)
			ans2.push_back("DEFICIENT");
		else if (ans > a)
			ans2.push_back("ABUNDANT");
	}
	for (int i = 0; i < ans1.size(); ++i)
		cout << string(5-dig(ans1[i]), ' ') << ans1[i] << "  " << ans2[i] << '\n';
	cout << "END OF OUTPUT\n";
return 0;}

