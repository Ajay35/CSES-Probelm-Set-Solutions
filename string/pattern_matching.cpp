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
  int n,m,i,j;
  string text,pattern;
  cin>>text>>pattern;
  m=pattern.size();
  n=text.size();
  vi lps(m);
  j=0;
  for(i=1;i<m;i++)
  {
  	while(j>0 && pattern[j]!=pattern[i])
  		j=lps[j-1];
  	if(pattern[i]==pattern[j])
  	{
  		lps[i]=j+1;
  		j++;
  	}
  }
  i=0;
  j=0;
  int c=0;
  while(i<n)
  {
	if(text[i]==pattern[j])
	{
		j++;
		i++;
	}
	if(j==m)
	{
        c++;
        j=lps[j-1]; 
    }
    else if(i<n && pattern[j]!=text[i])
    {
    	if(j!=0) 
        	j=lps[j-1]; 
        else
        	i=i+1; 
    }
  }
  cout<<c;
  return 0;
}