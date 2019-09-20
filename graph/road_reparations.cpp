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

const int N=1e5+5;
vector<int> parent, ran;

void make_set(int v) {
    parent[v] = v;
    ran[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ran[a] < ran[b])
            swap(a, b);
        parent[b] = a;
        if (ran[a] == ran[b])
            ran[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
int main()
{      
  fastio();
  //input();
	  int n,m,i;
	cin>>n>>m;
	vector<Edge> edges;
	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edges.pb({a,b,c});
	}
	ll cost = 0;
	int c=0;
	vector<Edge> result;
	parent.resize(n+1);
	ran.resize(n+1);
	for (int i = 1; i<=n; i++)
		make_set(i);

	sort(edges.begin(), edges.end());

	for (Edge e : edges) 
	{
	    if (find_set(e.u) != find_set(e.v)) 
	    {
	    	c++;
	        cost += e.weight;
	        result.push_back(e);
	        union_sets(e.u, e.v);
	    }
	    if(c==n-1) break;
	}
  if(c==n-1)
  	cout<<cost;
  else
  	cout<<"IMPOSSIBLE";
  return 0;
}