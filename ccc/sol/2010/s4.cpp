#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int n;
	scanf("%d",&n);
	vector<vector<int>> dp (n, vector<int> (n,-1));
	vector<vector<vector<int>>> etop (1000, vector<vector<int>> (1000, vector<int> ()));
	vector<vector<pair<int,pair<int,int>>>> ptoe;
	for (int i = 0; i < n; ++i){
		int e;
		scanf("%d",&e);
		
	}
	return 0;
}
