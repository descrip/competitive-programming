#include <vector>
#include <utility>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("cowjog.in");
	int N, T; fin >> N >> T;
	vector<pair<long long,long long>> V (N);
	for (int i = 0; i < N; ++i)
		fin >> V[i].first >> V[i].second;
	V[V.size()-1].first += V[V.size()-1].second * T;
	int ans = 1;
	for (int i = V.size()-2; i >= 0; --i){
		V[i].first += V[i].second * T;
		if (V[i].first >= V[i+1].first) V[i].first = V[i+1].first;
		else ++ans;
	}
	ofstream fout ("cowjog.out");
	fout << ans << '\n';
	fout.close();
	fin.close();
return 0;}
