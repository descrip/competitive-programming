#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

int N, val[2000], pset[2000], setrank[2000];

int findset(int n){
	return (pset[n] == n) ? n : (pset[n] = findset(pset[n]));
}

void unionset(int a, int b){
	if (findset(a) == findset(b)) return;
	int x = findset(a), y = findset(b);
	if (setrank[x] > setrank[y])
		pset[y] = x;
	else{
		pset[x] = y;
		if (setrank[x] == setrank[y]) ++setrank[y];
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("superbull.in");
	fin >> N;
	for (int i = 0; i < N; ++i){
		fin >> val[i];
		pset[i] = i;
	}
	vector<pair<int,pair<int,int>>> edges;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			edges.push_back({val[i]^val[j],{i,j}});
	sort(edges.begin(),edges.end(),greater<pair<int,pair<int,int>>>());
	long long ans = 0;
	for (auto e : edges){
		if (findset(e.second.first) != findset(e.second.second)){
			ans += e.first;
			unionset(e.second.first,e.second.second);
		}
	}
	ofstream fout ("superbull.out");
	fout << ans << '\n';
	fin.close(); fout.close();
return 0;}
