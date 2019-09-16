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

const int M=100005;
int a[101];

int main()
{      
  fastio();
  //input();
  int n,i,j,t;
  cin>>n;
  for(i=0;i<n;i++)
  	cin>>a[i];
  int m[M+10];
	for(i=0; i<M+10; i++) m[i]=0;
	m[0]=1;
	for(i=0; i<n; i++)
		for(j=M; j>=a[i]; j--)
			m[j] |= m[j-a[i]];
  set<int> ans;
  
  	for(j=1;j<=100000;j++){
  		if(m[j])
  			ans.insert(j);
  	}
  cout<<ans.size()<<"\n";
  for(int i:ans)
  	cout<<i<<" ";
  return 0;
}