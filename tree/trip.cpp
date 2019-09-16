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
bool check(int a[],int n)
{
	for(int i=1;i<n-1;i++)
	{
		if(a[i]!=-1 && a[i-1]!=a[i+1])
			return 1;
	}
	return 0;
}

int main()
{      
  fastio();
  input();
  int n,k,i,j,t;
  cin>>t;
  while(t--)
  {
  	cin>>n>>k;
  	int a[n];
  	for(i=0;i<n;i++)
  		cin>>a[i];
  	if(k==1 && n>1)
  	{
  		cout<<"NO"<<"\n";
  		continue;
  	}
  	else if(k==1 && n==1)
  	{
  		cout<<"YES"<<"\n";
  		cout<<1<<"\n";
  		continue;
  	}
  	if(k==2 && check(a,n))
  	{
  		cout<<"NO"<<"\n";
  		continue;
  	}
  	bool pos=1;
  	int prev=0,cur=1;
  	vi ans;
  	for(i=0;i<n;i++)
  	{
  		if(a[i]==-1)
  		{
  			int c=0;
  			if(prev==cur)
  			{
  				cur+=1;
  				if(cur>k)
  					cur=1;
  			}
  			if(i<n-1)
  			{
  				if(cur==a[i+1])
  					cur++;
  				if(cur>k)
  					cur=1;
  			}
  			if(cur==prev)
  			{
  				pos=0;
  				break;
  			}
  			ans.pb(cur);
  			prev=cur;
  		}
  		else
  		{
  			ans.pb(a[i]);
  			prev=a[i];
  		}
  	}
  	if(pos)
  	{
  		cout<<"YES"<<"\n";
  		for(i=0;i<ans.size();i++)
  			cout<<ans[i]<<" ";
  		cout<<"\n";
  	}
  	else
  	{
  		cout<<"NO"<<"\n";
  	}
  }
  return 0;
}