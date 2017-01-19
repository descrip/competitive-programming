//TODO: FINALIZE

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int ans = 0, n;
vector<int> path;
vector<pair<int,int>> p;

int cross(int x1, int y1, int x2, int y2){
	return y2*x1 - x2*y1;
}

int direction(int x1,int y1,int x2, int y2,int x3, int y3){
	return cross(x2-x1,y2-y1,x3-x1,y3-y1);
}

int onseg(int x1, int y1, int x2, int y2, int x3, int y3){
	if (min(x1,x2) <= x3 && x3 <= max(x1,x2) && min(y1,y2) <= y3 && y3 <= max(y1,y2))
		return true;
	return false;
}

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int d1 = direction(x3,y3,x4,y4,x1,y1);
    int d2 = direction(x3,y3,x4,y4,x2,y2);
    int d3 = direction(x1,y1,x2,y2,x3,y3);
    int d4 = direction(x1,y1,x2,y2,x4,y4);
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    else if (d1 == 0 && onseg(x3,y3,x4,y4,x1,y1))
        return true;
    else if (d2 == 0 && onseg(x3,y3,x4,y4,x2,y2))
        return true;
    else if (d3 == 0 && onseg(x1,y1,x2,y2,x3,y3))
        return true;
    else if (d4 == 0 && onseg(x1,y1,x2,y2,x4,y4))
        return true;
    else
        return false;
}

void recur(){
	if (path.size() == n){

		for (int i = 1; i < n; ++i){
				if (i != 1 && i != n-1 && intersect(
							p[path[i]].first,
							p[path[i]].second,
							p[path[i-1]].first,
							p[path[i-1]].second,
							p[path[0]].first,
							p[path[0]].second,
							p[path[n-1]].first,
							p[path[n-1]].second)){
					return;
				}
			for (int j = i+2; j < n; ++j)
				if (intersect(
							p[path[i]].first,
							p[path[i]].second,
							p[path[i-1]].first,
							p[path[i-1]].second,
							p[path[j]].first,
							p[path[j]].second,
							p[path[j-1]].first,
							p[path[j-1]].second)){
					return;
				}
		}
		++ans;
		return;
	}
	for (int i = 0; i < n; ++i){
		if (find(path.begin(),path.end(),i) == path.end()){
			/*
			bool ok = true;
			if (path.size() >= 2){
				for (int j = 1; j < path.size(); ++j){
					if (intersect(p[j].first,p[j].second,p[j-1].first,p[j-1].second,p[i].first,p[i].second,p[*path.rbegin()].first,p[*path.rbegin()].second)){

						//printf("%d %d %d %d %d %d %d %d\n", p[j].first,p[j].second,p[j-1].first,p[j-1].second,p[i].first,p[i].second,p[*path.rbegin()].first,p[*path.rbegin()].second);
						ok = false;
						break;
					}
				}
			}
			if (ok){
				path.pb(i);
				recur();
				path.erase(path.end()-1);
			}
			*/
			path.pb(i);
			recur();
			path.erase(path.end()-1);
		}
	}
}

int main(){
	scan(n);
	for (int i = 0; i < n; ++i){
		int a, b;
		scan(a);
		scan(b);
		p.pb({a,b});
	}
	path.pb(0);
	recur();
	printf("%d\n",ans/2);
}
