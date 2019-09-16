#include <bits/stdc++.h>
#define N 101
#define INF INT_MAX
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


int cost[N][N];

int minimum(int a, int b) {
   return (a<b)?a:b;
}

int shortKEdgePath(int u, int v, int edge)
{
   if(edge==0 && u==v)     
      return 0;
   if(edge==1 && cost[u][v]!=INF)
      return cost[u][v];
   if(edge<=0)
      return INF;
   int shortPath = INF;

   for(int i=0;i<N; i++)
   {
      if(cost[u][i]!=INF && u!=i && v!=i)
      {
         int tempRes=shortKEdgePath(i,v,edge-1);
         if(tempRes!=INF)
            shortPath=minimum(shortPath,cost[u][i]+tempRes);
      }
   }
   return shortPath;
}

int main()
{
   fastio();
   input();
   int i,n,m,k;
   cin>>n>>m>>k;
   for(i=0;i<m;i++)
   {
      int a,b,c;
      cin>>a>>b>>c;
      cost[a-1][b-1]=c;
   }
   cout<<shortKEdgePath(0,n-1,k);
}