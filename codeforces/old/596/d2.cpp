#include <bits/stdc++.h>
using namespace std;
#define N (1<<11)
#define EPS (1e-7)
#define INFP (1<<30)
#define LL long long

int n,h,x[N],L[N],R[N];
double p,dp[N][N][2][2];

double solve(int l,int r,int sl,int sr)
{
	if(dp[l][r][sl][sr]>-EPS)
		return dp[l][r][sl][sr];
	double res=0;
	if(l==r)
	{
		if(!sl) res+=p*min(x[l]-x[l-1],h); else res+=p*min(x[l]-x[l-1]-h,h);
		if(!sr) res+=(1.-p)*min(x[r+1]-x[r],h); else res+=(1.-p)*min(x[r+1]-x[r]-h,h);
	}
	else
	{
		//LL
		if(!sl)
			res+=p/2*(min(x[l]-x[l-1],h)+solve(l+1,r,0,sr));
		else
			res+=p/2*(min(x[l]-x[l-1]-h,h)+solve(l+1,r,0,sr));
		cout << "1 " << l << ' ' << r << ' ' << sl << ' ' << !sr << ' ' << res << '\n';

		//RR
		if(!sr)
			res+=(1.-p)/2*(min(x[r+1]-x[r],h)+solve(l,r-1,sl,0));
		else
			res+=(1.-p)/2*(min(x[r+1]-x[r]-h,h)+solve(l,r-1,sl,0));
		cout << "2 " << l << ' ' << r << ' ' << sl << ' ' << !sr << ' ' << res << '\n';

		//LR
		if(R[l]>=r)
		{
			if(!sr) res+=(1.-p)/2*(x[r]-x[l]+min(x[r+1]-x[r],h));
			else res+=(1.-p)/2*(x[r]-x[l]+min(x[r+1]-x[r]-h,h));
		}
		else
			res+=(1.-p)/2*(x[R[l]]-x[l]+h+solve(R[l]+1,r,1,sr));
		cout << "3 " << l << ' ' << r << ' ' << sl << ' ' << !sr << ' ' << res << '\n';

		//RL
		if(L[r]<=l)
		{
			if(!sl) res+=p/2*(x[r]-x[l]+min(x[l]-x[l-1],h));
			else res+=p/2*(x[r]-x[l]+min(x[l]-x[l-1]-h,h));
		}
		else
			res+=p/2*(x[r]-x[L[r]]+h+solve(l,L[r]-1,sl,1));
		cout << "4 " << l << ' ' << r << ' ' << sl << ' ' << !sr << ' ' << res << '\n';

	}
	//cout << l << ' ' << r << ' ' << sl << ' ' << !sr << ' ' << res << '\n';
	return dp[l][r][sl][sr]=res;
}

int main()
{
	cin>>n>>h>>p,x[0]=-INFP,x[n+1]=INFP;
	for(int i=1;i<=n;i++)
    	scanf("%d",x+i);
	sort(x,x+n+2);

	for(int i=1;i<=n;i++)
		if(x[i]-x[i-1]>=h) L[i]=i;
		else L[i]=L[i-1];
	for(int i=n;i>=1;i--)
		if(x[i+1]-x[i]>=h) R[i]=i;
		else R[i]=R[i+1];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<2;k++)
				for(int r=0;r<2;r++)
					dp[i][j][k][r]=-1;

	printf("%.9f\n",solve(1,n,0,0));
	return 0;
}
