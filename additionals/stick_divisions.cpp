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

void fasti()
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

const int N=2e5+5;
int a[N],n;

int main()
{      
  fasti();
  //input();
  int n,x,i;
  cin>>x>>n;
  priority_queue<ll,vll,greater<ll>> pq;
  for(i=0;i<n;i++)
  {
    ll p;
    cin>>p;
    pq.push(p);
  }

  ll ans=0;
  while(pq.size()>1)
  {
    ll k=pq.top();
    pq.pop();
    k+=pq.top();
    pq.pop();
    ans+=k;
    pq.push(k);
  }
  cout<<ans;
  return 0;
}