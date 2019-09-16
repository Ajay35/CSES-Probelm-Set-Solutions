#include <cassert>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <array>
#include <map>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctgmath>
#include <set>
#include <queue>
#include <fstream>
#include <ostream>
#include <random>
#include <chrono>
using namespace std;

#define int long long
#define MOD 1000000007

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

const int N=1e5+5;
int dp[N];
vector<int> g[N];

int dfs(int u,int t)
{
    if(u==t)
        return 1;
    int ans=0;
    if(dp[u]==-1)
    {
	    for(int v:g[u])
	    	ans+=dfs(v,t);
	    dp[u]=ans%MOD;
	}
    return dp[u];
}
signed main()
{
	fastio();
	//input();
	int n, m;
	cin >> n >> m;

	while(m--)
	{
		int i, j;
		cin >> i >> j;
		g[i].push_back(j);
	}
	memset(dp,-1,sizeof dp);
	cout<<dfs(1,n);
}