#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void fastio()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void input()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

ll mod=1000000007;
string k;
ll d;

ll dp[10005][105][3];

ll recur(ll ind,ll rem,ll check)
{
	if(ind==k.size() && rem==0){return 1;}
	if(ind==k.size())return 0;
	if(dp[ind][rem][check]!=-1)return dp[ind][rem][check];
	
	ll ans=0;
	if(check)
	{
		for(ll i=0;i<=9;i++)
		{
			ans=(ans+recur(ind+1,(rem+i)%d,1))%mod;
		}
	}
	else
	{
		for(ll i=0;i<=k[ind]-'0';i++)
		{
			if(i<k[ind]-'0')
				ans=(ans+recur(ind+1,(rem+i)%d,1))%mod;
			else
				ans=(ans+recur(ind+1,(rem+i)%d,0))%mod;
		}
	}
	dp[ind][rem][check]=ans;
	return ans;
}

int main()
{
	fastio();
	input();
	cin>>k>>d;
	memset(dp,-1,sizeof(dp));
	ll ans=recur(0,0,0)-1;
	if(ans<0)ans+=mod;
	cout<<ans;
}
