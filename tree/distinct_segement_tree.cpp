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
// Each segment of the segment tree would be a set 
// to maintain distinct elements 
set<int>* segment; 

// Build the segment tree 
// i denotes current node, s denotes start and 
// e denotes the end of range for current node 
void build(int i, int s, int e, int arr[]) 
{ 

	// If start is equal to end then 
	// insert the array element 
	if (s == e) { 
		segment[i].insert(arr[s]); 
		return; 
	} 

	// Else divide the range into two halves 
	// (start to mid) and (mid+1 to end) 
	// first half will be the left node 
	// and the second half will be the right node 
	build(2 * i, s, (s + e) / 2, arr); 
	build(1 + 2 * i, 1 + (s + e) / 2, e, arr); 

	// Insert the sets of right and left 
	// node of the segment tree 
	segment[i].insert(segment[2 * i].begin(), 
					segment[2 * i].end()); 

	segment[i].insert(segment[2 * i + 1].begin(), 
					segment[2 * i + 1].end()); 
} 

// Query in an range a to b 
set<int> query(int node, int l, int r, int a, int b) 
{ 
	set<int> left, right, result; 

	// If the range is out of the bounds 
	// of this segment 
	if (b < l || a > r) 
		return result; 

	// If the range lies in this segment 
	if (a <= l && r <= b) 
		return segment[node]; 

	// Else query for the right and left 
	// leaf node of this subtree 
	// and insert them into the set 
	left = query(2 * node, l, (l + r) / 2, a, b); 
	result.insert(left.begin(), left.end()); 

	right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b); 
	result.insert(right.begin(), right.end()); 

	// Return the result 
	return result; 
} 

// Initialize the segment tree 
void init(int n) 
{ 
	// Get the height of the segment tree 
	int h = (int)ceil(log2(n)); 
	h = (2 * (pow(2, h))) - 1; 

	// Initialize the segment tree 
	segment = new set<int>[h]; 
} 

// Function to get the result for the 
// subarray from arr[l] to arr[r] 

// Driver code 
int main() 
{ 
	fastio();
	//input();
	int n,q,i;
	cin>>n>>q;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	init(n); 
	build(1, 0, n - 1, a); 

	for(i=0;i<q;i++){ 
		int l,r;
		cin>>l>>r;
		set<int> ans = query(1, 0, n - 1, l-1, r-1); 
		cout << ans.size() << endl; 
	}
	return 0; 
} 
