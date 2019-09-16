/**
*	  Name: Ajay
*	  Institute: IIITH 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#define ll long long
#define inf 0x7fffffff
#define mod 1000000007
#define pb push_back
#define ppi pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<ppi>
#define vll vector<ll>
#define mp make_pair
#define fi first
#define se second
using namespace std;

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

int main()
{      
  fastio();
  //input();
  ll n,i;
  cin>>n;
  ll sum=(n*(n+1))/2;
  bool vis[1000001];
  memset(vis,false,sizeof vis);
  if(sum&1)
  	cout<<"NO";
  else
  {
  	ll temp=sum/2;
  	i=n;
  	int c=0;
  	vi ans1;
  	while(i>=1 && temp>0)
  	{
  		if(i<=temp)
  		{
  			temp-=i;
  			ans1.pb(i);
  			vis[i]=1;
  		}
  		i--;
  	}

  	if(temp==0)
  	{
  		cout<<"YES"<<"\n";
  		cout<<ans1.size()<<"\n";
  		for(i=ans1.size()-1;i>=0;i--)
  			cout<<ans1[i]<<" ";
  		cout<<"\n";
  		cout<<n-ans1.size()<<"\n";
  		for(i=1;i<=n;i++)
  			if(!vis[i])
  				cout<<i<<" ";
  	}
  	else
  		cout<<"NO";
  }
  return 0;
}