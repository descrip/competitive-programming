#include <bits/stdc++.h>
using namespace std;

const int LIM = 5000;

bool isPent(int a){
	double tmp = (1 + sqrt(24 * a + 1)) / 6;
	return (tmp == floor(tmp));
}

int toPent(int a){
	return a * (3*a - 1) / 2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i <= LIM; ++i)
		for (int j = i+1; j <= LIM; ++j)
			if (isPent(toPent(j) - toPent(i)) && isPent(toPent(j) + toPent(i))){
				cout << toPent(j) - toPent(i) << '\n';
				return 0;
			}
return 0;}

