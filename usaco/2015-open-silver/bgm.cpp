#include <fstream>
#include <map>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("bgm.in");
	int N; fin >> N;
	map<char,int> m;
	m['B'] = 0;
	m['E'] = 1;
	m['S'] = 2;
	m['I'] = 3;
	m['G'] = 4;
	m['O'] = 5;
	m['M'] = 6;
	static long long A[7][7];
	for (int i = 0; i < N; ++i){
		char c; int a; fin >> c >> a;
		++A[m[c]][(a%7+7)%7];
	}
	long long ans = 0;
	for (int b = 0; b < 7; ++b)
	for (int e = 0; e < 7; ++e)
	for (int s = 0; s < 7; ++s)
	for (int i = 0; i < 7; ++i)
	for (int g = 0; g < 7; ++g)
	for (int o = 0; o < 7; ++o)
	for (int m = 0; m < 7; ++m)
		if ((b+e+s+s+i+e) % 7 == 0 ||
			(g+o+e+s) % 7 == 0 ||
			(m+o+o) % 7 == 0)
			ans += A[0][b] * A[1][e] * A[2][s] * 
				A[3][i] * A[4][g] * A[5][o] * A[6][m];
	ofstream fout ("bgm.out");
	fout << ans << '\n';
	fin.close(); fout.close();
return 0;}
