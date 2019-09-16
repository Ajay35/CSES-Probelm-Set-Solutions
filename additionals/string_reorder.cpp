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

string rearrangeString(string s)
{
	int i,j,n=s.size();
	int c[26]={0};
	string ans="";
	for(i=0;i<n;i++)
		c[s[i]-'A']++;
	for(i=0;i<26;)
	{
		if(c[i]==1)
		{
			ans+=i+'A';
			c[i]--;
			continue;
		}
		if(c[i]>0)
		{
			for(j=i+1;j<26;j++)
			{
				cout<<"in j"<<j<<endl;
				if(c[j]>0)
				{
					cout<<"inside"<<endl;
					bool turn=0;
					while(c[i]>0 && c[j]>0)
					{
						if(!turn)
						{
							ans+=i+'A';
							c[i]--;
							turn=!turn;
						}
						else
						{
							ans+=j+'A';
							c[j]--;
							turn=!turn;
						}
					}
					break;
				}
			}
		}
		while(c[i]<=0)
			i++;

	}
	return ans;
}


int main()
{      
  fastio();
  input();
  string s;
  cin>>s;
  cout<<rearrangeString(s);
  return 0;
}