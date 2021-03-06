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
int taken[200005];

int main()
{      
  fastio();
  //input();
  int n,m,i,k,j,c=0;
  cin>>n>>m>>k;
  int a[n],b[m];
  for(i=0;i<n;i++)
  	cin>>a[i];
  for(i=0;i<m;i++)
  	cin>>b[i];
  sort(a,a+n);
  sort(b,b+m);
  i=0,j=0;
  while(i<n && j<m)
  {
  	if(a[i]+k<b[j])
  		i++;
  	else if(a[i]-k>b[j])
  		j++;
  	else
  		i++,j++,c++;
  }
  cout<<c;
  return 0;
}