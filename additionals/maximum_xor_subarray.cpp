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

#define INT_SIZE 32 
  

struct TrieNode 
{ 
    int value;
    TrieNode *arr[2]; 
}; 
TrieNode *newNode() 
{ 
    TrieNode *temp = new TrieNode; 
    temp->value = 0; 
    temp->arr[0] = temp->arr[1] = NULL; 
    return temp; 
} 

void insert(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--) 
    { 
        bool val = pre_xor & (1<<i); 
        if (temp->arr[val] == NULL) 
            temp->arr[val] = newNode(); 
  
        temp = temp->arr[val]; 
    }
    temp->value = pre_xor; 
} 
int query(TrieNode *root, int pre_xor) 
{
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    {
        bool val = pre_xor & (1<<i);  
        if (temp->arr[1-val]!=NULL) 
            temp = temp->arr[1-val]; 
        else if (temp->arr[val] != NULL) 
            temp = temp->arr[val]; 
    } 
    return pre_xor^(temp->value); 
}
int maxSubarrayXOR(int arr[], int n) 
{
    TrieNode *root = newNode(); 
    insert(root,0);
    int result=-inf, pre_xor =0;    
    for (int i=0; i<n; i++) 
    {
        pre_xor = pre_xor^arr[i]; 
        insert(root, pre_xor); 
        result = max(result, query(root, pre_xor)); 
    } 
    return result; 
} 
int main()
{
	fastio();
	//input();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSubarrayXOR(a,n);
    return 0;
}