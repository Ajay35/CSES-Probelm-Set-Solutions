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
  int n,m,i,j,t;
  cin>>n;
  vii tasks;
  for(i=0;i<n;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	tasks.pb(mp(x,y));
  }
  ll cur=0,ans=0;
  sort(tasks.begin(), tasks.end());
  for(i=0;i<n;i++)
  {
  	ans+=tasks[i].se-(tasks[i].fi+cur);
  	cur+=tasks[i].fi;
  }
  cout<<ans;
  return 0;
}