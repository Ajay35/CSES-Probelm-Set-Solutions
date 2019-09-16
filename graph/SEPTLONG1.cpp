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
#define pb  push_back
#define ppi pair<int,int>
#define vi  vector<int>
#define vvi vector<vector<int>>
#define vii vector<ppi>
#define vll vector<ll>
#define mp  make_pair
#define fi  first
#define se  second
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

void multiply(ll f[][2],ll g[][2])
{
    ll a=(f[0][0]*g[0][0]+f[0][1]*g[1][0])%10;
    ll b=(f[0][0]*g[0][1]+f[0][1]*g[1][1])%10;
    ll c=(f[1][0]*g[0][0]+f[1][1]*g[1][0])%10;
    ll d=(f[1][0]*g[0][1]+f[1][1]*g[1][1])%10;
    
    f[0][0]=a;
    f[0][1]=b;
    f[1][0]=c;
    f[1][1]=d;
}
void power(ll f[2][2],ll n)
{
    ll g[2][2]={{1,1},{1,0}};
    if(n==0||n==1)
    return;
    power(f,n/2);
    multiply(f,f);
    
    if(n%2==1)
    multiply(f,g);
}
ll nthfib(ll n)
{
    ll f[2][2]={{1,1},{1,0}};
    if(n==0)
    	return 0;
    power(f,n-1);
    return f[0][0]%10;
}

int main()
{
  fastio();
  input();
  ll n,m,i,j,t;
  cin>>t;
  int ans[64];
  for(i=0;i<=63;i++)
  {
  	ans[i]=nthfib((1<<i)-1);
  	cout<<i+1<<" "<<ans[i]<<"\n";
  }
  while(t--)
  {
  	cin>>n;
	int p=(int)log2(n);
   	cout<<ans[p]<<"\n";
  }
  return 0;
}