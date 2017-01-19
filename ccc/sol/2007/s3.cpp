#include <cstdio>
#include <array>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 9999;

int main(){
	int n;
	scanf("%d",&n);
	array<int,MAX> start, end;
	for (int i = 0; i < n; ++i)
		scanf("%d %d",&start[i],&end[i]);
	int a, b;
	while (true){
		scanf("%d %d",&a,&b);
		if (a == 0 && b == 0)
			break;
		queue<pair<int,int>> q;
		//q.clear();
		q.push(make_pair(a,0));
		bool first = true;
		while (!q.empty()){
			//printf("%d %d\n",q.front().first,q.front().second);
			if (q.front().first == b && !first)
				break;
			else if (q.front().first == a && !first)
				q.pop();
			else{
				for (int i = 0; i < n; ++i)
					if (start[i] == q.front().first)
						q.push(make_pair(end[i],q.front().second + 1));
				q.pop();
				first = false;
			}
		}
		if (q.empty())
			puts("No");
		else
			printf("Yes %d\n",q.front().second - 1);
	}
	return 0;
}
