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

ll power(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
			res=res*x;
		x=x*x;
		y=y>>1;
	}
	return res;
}

ll pisanoPeriod(ll m)
{ 
    int previous=0,current=1,i;
    for (i=0;i<100;i++)
    { 
        previous=current;
        current= (previous + current) % m ;
        
        if (previous == 0 and current == 1) 
            return i + 1;
    }
}

ll fibonacciModulo(ll n,ll m)
{ 
    int i;
    ll pisano_period = pisanoPeriod(m);
    n = n % pisano_period ;
      
    ll previous=0;
    ll current=1;
      
    for(i=0;i<n-1;i++)
    {
        previous=current;
        current=previous+current;
    }
    return (current % m);
}

int main()
{      
  fastio();
  input();
  ll n,m,i,j,t;
  cin>>t;
  while(t--)
  {
	  cin>>n;
	  ll p=log2(n);
	  ll ans=power(2,p);
	  cout<<(fibonacciModulo(ans,10)+1)%10;
  }
  return 0;
}