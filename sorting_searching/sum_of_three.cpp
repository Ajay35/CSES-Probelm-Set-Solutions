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

bool cmp(ppi a,ppi b)
{
	return a.fi<=b.fi;
}



int main()
{      
  fastio();
  //input();
  ll n,s,i,j,t;
  cin>>n>>s;
  vector<pair<ll,int>> a;
  for(i=0;i<n;i++)
  {
  	ll x;
  	cin>>x;
  	a.pb(mp(x,i+1));
  }
  sort(a.begin(),a.end(),cmp);
  bool pos=0;
  vi ans;
  for(i=0;i<n-2;i++)
  {
  	int l=i+1,r=n-1;
  	while(l<r)
  	{
  		ll sum=a[i].fi+a[l].fi+a[r].fi;
  		if(sum==s)
  		{
  			ans.pb(a[i].se);
  			ans.pb(a[l].se);
  			ans.pb(a[r].se);
  			sort(ans.begin(),ans.end());
  			pos=1;
  			break;
  		}
  		else if(sum<s)
  			l++;
  		else if(sum>s)
  			r--;
  	}
  	if(pos)break;
  }
  if(!pos)
  	cout<<"IMPOSSIBLE";
  else
  	for(int p=0;p<ans.size();p++)
  		cout<<ans[p]<<" ";
  return 0;
}