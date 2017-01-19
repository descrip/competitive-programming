#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define max_ele(a) a[max_element(a.begin(),a.end()) - a.begin()]
#define min_ele(a) a[min_element(a.begin(),a.end()) - a.begin()]

const int MAX = 1001;

int main(){
	int N;
	cin >> N;
	int a[1001], buff;
	memset(a,0,sizeof(a));
	for (int i = 0; i < N; i++){
		cin >> buff;
		a[buff]++;
	}
	
	int best = 0, sbest = 0;
	for (int i = 0; i < MAX; i++)
		if (a[i] > best){
			sbest = best;
			best = a[i];
		}
		else if (a[i] > sbest)
			sbest = a[i];
	
	int bmax = 0, bmin = MAX, smax = 0, smin = MAX;
	for (int i = 0; i < MAX; i++){
		if (a[i] == best){
			bmin = min(bmin,i);
			bmax = max(bmax,i);
		}
		if (a[i] == sbest){
			smax = max(smax,i);
			smin = min(smin,i);
		}
	}
	cout << max(abs(bmax - bmin), max(abs(smax - bmin), abs(bmax - smin))) << endl;
	return 0;
}
