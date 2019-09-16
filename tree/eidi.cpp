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
  input();
  int n,i,j,t;
  cin>>t;
  while(t--)
  {
  	vector<ppi> money;
  	int x,y,z;
  	int p,q,r;
  	cin>>x>>y>>z;
  	cin>>p>>q>>r;
  	money.pb(mp(x,p));
  	money.pb(mp(y,q));
  	money.pb(mp(z,r));
  	bool pos=1;
  	sort(money.begin(), money.end());
  	for(i=1;i<3;i++)
  	{
  		if(money[i-1].fi<money[i].fi && money[i-1].se>=money[i].se)
  		{
  			pos=0;
  			break;
  		}

  		else if(money[i].fi==money[i-1].fi && money[i-1].se!=money[i].se){
  			pos=0;
  			break;
  		}
  	}
  	if(pos)
  		cout<<"FAIR"<<"\n";
  	else
  		cout<<"NOT FAIR"<<"\n";
  }
  return 0;
}