#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int K;
	scanf("%d",K);
	int A[25];
	for (int i = 0; i < K; i++)
		scanf("%d",&A[i]);
	vector<pair<int,int>> G;
	for (int i = 0; i < K; i++)
		if (A[i] == 1){
			for (int j; j < K; j++)
				if (A[j] == 0)
					G.push_back(make_pair(i,j - i));
			i = j;
		}

}
