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
  int n,i;
  cin>>n;
  vi x;
  if(n%2)
  {
	  for(i=1;i<=n;i+=2)
	  	x.pb(i);
	  for(i=2;i<=n;i+=2)
	  	x.pb(i);
	  bool pos=1;
	  for(i=1;i<x.size();i++)
	  {
	  	if(abs(x[i]-x[i-1])==1)
	  	{
	  		pos=0;
	  		break;
	  	}
	  }
	  if(pos)
	  {
	  	for(i=0;i<x.size();i++)
	  		cout<<x[i]<<" ";
	  }
	  else
	  	cout<<"NO SOLUTION";
  }
  else
  {
  	for(i=2;i<=n;i+=2)
	  	x.pb(i);
	  for(i=1;i<=n;i+=2)
	  	x.pb(i);
	  bool pos=1;
	  for(i=1;i<x.size();i++)
	  {
	  	if(abs(x[i]-x[i-1])==1)
	  	{
	  		pos=0;
	  		break;
	  	}
	  }
	  if(pos)
	  {
	  	for(i=0;i<x.size();i++)
	  		cout<<x[i]<<" ";
	  }
	  else
	  	cout<<"NO SOLUTION";
  }
  return 0;
}