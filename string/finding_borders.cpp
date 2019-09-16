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

const int N=1e6+5;
int border[N];

void calculate_border(string s)
{
  int i=1,j=-1,n=s.size();
  border[0]=-1;
  while(i<n)
  {
    while(j>=0 && s[i]!=s[j+1])
    	j=border[j];
    if(s[i]==s[j+1]) 
    	j++;
    border[i++]=j;
  }
}

int main()
{      
  fastio();
  string s;
  cin>>s;
  int i;
  int len = s.length();
  vi b(len-1); 
  
  int p=0;
  
  for(i=1;i<len-1;i++)
  {
    while(p>0 && s[p]!=s[i])
    	p=b[p-1];
    if(s[p]==s[i])
    {
    	b[i]=p+1;
    	p++;
    }
  }
      
  // look up
  p=len-1;
  vi ans;
  while(p>0)
  {
  	p=b[p-1];
  	if(s[p]==s[len-1])
  		ans.pb(p+1);
  }
  for(i=ans.size()-1;i>=0;i--)
  	cout<<ans[i]<<" ";
  return 0;
}