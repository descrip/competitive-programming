#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<vector<int>> dolls (k);
	for (int j = 0; j < k; ++j){
		int m; cin >> m;
		for (int i = 0; i < m; ++i){
			int a; cin >> a;
			dolls[j].push_back(a);
		}
	}
	int ans = 0;
	int orig = dolls.size();
	for (int i = 0; i < orig; ++i){
		if (dolls[i][0] != 1){
			while (dolls[i].size() != 1){
				dolls.push_back(vector<int>(1));
				dolls[dolls.size()-1][0] = dolls[i][dolls[i].size()-1];
				++ans;
				dolls[i].erase(dolls[i].begin()+dolls[i].size()-1);
			}
			continue;
		}
		while (dolls[i][dolls[i].size()-1] - dolls[i][0] + 1 != dolls[i].size()){
			dolls.push_back(vector<int>(1));
			dolls[dolls.size()-1][0] = dolls[i][dolls[i].size()-1];
			dolls[i].erase(dolls[i].begin()+dolls[i].size()-1);
			++ans;
		}
	}
	cout << ans + dolls.size() - 1 << '\n';
return 0;}
