/**
*	  Name: Ajay
*	  Institute: IIITH 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
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

const int N=200005;
int a[N],pre[N];

int main()
{      
  fastio();
  //input();
  ll i,n,s,cur=0,ans=0;
  cin>>n>>s;
  unordered_map<ll,int> prev_sum;
  for(i=0;i<n;i++)
  {
  	int x;
  	cin>>x;
  	cur+=x;
  	if(cur==s)
  		ans++;
  	if(prev_sum.find(cur-s)!=prev_sum.end())
  		ans+=prev_sum[cur-s];
  	prev_sum[cur]++;
  }
  cout<<ans;
  return 0;
}	