#include <iostream>
using namespace std;

int main(){
	bool isComp[999999];
	isComp[1] = 1;
	for (int i = 2; i < sizeof(isComp); i++)
		if (isComp[i] == 0)
			for (int j = 2; j < sizeof(isComp); j++)
				if (i * j < sizeof(isComp) - 1)
					isComp[i*j] = 1;
				else
					break;
	int cnt = 0;
	for (int i = 2; i < sizeof(isComp); i++)
		if (isComp[i] == 0){
			cnt++;
			if (cnt == 10001){
				cout << i << endl;
				break;
			}
		}
	return 0;	
}
