//for loops are cool
#include <bits/stdc++.h>
using namespace std;

struct cow{
	int x, y; char c;
};

bool operator<(const cow &a, const cow &b){
	return a.x < b.x;
}

int main(){
	ifstream fin ("cowrect.in");
	int n; fin >> n;
	vector<cow> cows (n);
	for (int i = 0; i < n; ++i)
		fin >> cows[i].x >> cows[i].y >> cows[i].c;
	vector<vector<cow>> xtoc (1002);
	for (int i = 0; i < n; ++i)
		xtoc[cows[i].x].push_back(cows[i]);
	sort(cows.begin(),cows.end());
	int num = 1, area = 0;
	for (int i = 0; i < n; ++i){
		if (cows[i].c == 'G') continue;
		for (int j = i+1; j < n; ++j){
			if (cows[j].c == 'G') continue;
			for (int k = 0; k < xtoc.size(); ++k){
				int l = k+1, cnt = 0;
				for (int m = 0; m < xtoc[k].size(); ++m)
					if (min(cows[i].y,cows[j].y) <= xtoc[k][m].y && xtoc[k][m].y <= max(cows[i].y,cows[j].y)){
						if (xtoc[k][m].c == 'H') ++cnt;
						else cnt = -0x7fffffff;
					}
				if (cnt <= 0) continue;
				for (; l < xtoc.size(); ++l){
					int thiscnt = 0;
					for (int m = 0; m < xtoc[l].size(); ++m)
						if (min(cows[i].y,cows[j].y) <= xtoc[l][m].y && xtoc[l][m].y <= max(cows[i].y,cows[j].y)){
							if (xtoc[l][m].c == 'H') ++thiscnt;
							else thiscnt = -0x7fffffff;
						}
					if (thiscnt < 0) break;
					else cnt += thiscnt;
					if (num == cnt)
						area = min(area,abs(cows[j].y-cows[i].y)*abs(k-l));
					else if (cnt > num){
						//cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
						num = cnt;
						area = abs(cows[j].y-cows[i].y)*abs(k-l);
					}
				}
				k = l;
			}
		}
	}
	ofstream fout ("cowrect.out");
	fout << num << '\n' << area << '\n';
	fin.close(); fout.close();
return 0;}
