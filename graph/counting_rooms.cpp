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

const int N=1001;
char grid[N][N];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(int i,int j)
{
	if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='#')
		return;
	grid[i][j]='#';
	for(int k=0;k<4;k++)
		dfs(i+dx[k],j+dy[k]);
}
int main()
{
  fastio();
  //input();
  int i,j,c=0;
  cin>>n>>m;
  for(i=0;i<n;i++)
  	for(j=0;j<m;j++)
  		cin>>grid[i][j];
  for(i=0;i<n;i++)
  {
  	for(j=0;j<m;j++)
  	{
  		if(grid[i][j]=='.')
  		{
  			dfs(i,j);
  			c++;
  		}
  	}
  }
  cout<<c;
  return 0;
}