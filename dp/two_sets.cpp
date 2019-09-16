#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int n, t;
int c[501][250001];

ll f(int i,int s) 
{
	if(i==n) 
		return s==t;
	if(c[i][s]!=-1) 
		return c[i][s];
	ll k=f(i+1,s);
	if(s+i<=t) 
		k+=f(i+1,s+i);
	k=k%MOD;
	c[i][s]=k;
	return k;
}

int main()
{
	cin>>n;
	t=n*(n+1)/2;
	if(t%2) 
		cout<<"0\n";
	else
	{
		t/=2;
		memset(c,-1,sizeof c);
		ll r=f(1,0);
		if(r<0)
			r+=MOD;
		cout<<r<<"\n";
	}
}