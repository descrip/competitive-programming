#include <bits/stdc++.h>
using namespace std;
struct LINE{int m, s, id;}line[100002],st[100002];
int N, Q, t, ans[500002], top=-1, maxX=500000;
bool cmp(LINE x, LINE y){
    return (x.m < y.m)||(x.m==y.m && x.s<y.s);
}
bool check(LINE a, LINE b, LINE c){
   return 1LL*(a.s-c.s)*(b.m-a.m)<1LL*(a.s-b.s)*(c.m-a.m);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &Q);
    memset(ans, 0x3f, sizeof(ans));
    for(int i=0; i<N; i++){
        scanf("%d %d", &line[i].s, &line[i].m);
        line[i].id = i;
    }
    sort(line, line+N, cmp);
    for(int i=0; i<N; i++){
        while(top>=0 && st[top].m==line[i].m) top--;
        while(top>=1 && check(st[top-1], st[top], line[i])) top--;
        st[++top] = line[i];
    }
    for(int i=0, j=1; i<=top && j<=maxX; ){
        while(i<top && j<=maxX){
            long long y1 = (st[i+1].m - st[i].m) * j,
				 	  y2 = st[i].s - st[i+1].s;
            if (y1 < y2) {
				ans[j] = min(ans[j], st[i].id);
				j++;
			}
            else if (y1==y2) {
				ans[j] = min(ans[j], min(st[i].id, st[i+1].id));
				i++;
			}
            else i++;
        }
        if(i==top && j!=maxX){
            for(; j<=maxX; j++)
                ans[j] = min(ans[j], st[top].id);
        }
    }
    while(Q--){
        scanf("%d", &t);
        printf("%d\n", ans[t]);
    }
}
