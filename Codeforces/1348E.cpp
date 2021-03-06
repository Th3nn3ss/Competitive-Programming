#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<vector<long long>>> vvvl;
typedef vector<pair<int, int>> vpt;
typedef vector<pair<long long, long long>> vptl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
typedef map<int, int> mi;
typedef map<long long, long long> ml;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
const int MOD = 998244353;  
ll dp(vvl &DP, int &n, int &k, vi &a, vi &b, int x, int r, int g)
{
	if(x == n)
	{
		return 0;
	}
	if(DP[x][r] != -1)
	{
		return DP[x][r];
	}
	DP[x][r] = 0;
	int rem_r, rem_g;
	if(a[x] + b[x] >= k)
	{
		f(i, 1, min(a[x] + 1, k))
		{
			if((k - i) <= b[x])
			{
				rem_r = r + a[x] - i;
				rem_g = g + b[x] - (k - i);
				DP[x][r] = max(DP[x][r], 1 + (rem_r / k) + (rem_g / k) +
					dp(DP, n, k, a, b, x + 1, rem_r % k, rem_g % k)); 
			}
		}
	}
	rem_r = r + a[x];
	rem_g = g + b[x];
	DP[x][r] = max(DP[x][r], 
		(rem_r / k) + (rem_g / k) + 
			dp(DP, n, k, a, b, x + 1, rem_r % k, rem_g % k));
	return DP[x][r];
}
int solution(int tc)
{
	int n, k;
	cin>>n>>k;
	vi a(n), b(n);
	f(i, 0, n)
	{
		cin>>a[i]>>b[i];
	}
	vvl DP(n, vl(k, -1));
	cout<<dp(DP, n, k, a, b, 0, 0, 0)<<endl;
	return 1;
}
void testCase()
{
	int tc = 1;
	// cin>>tc;
	f(i, 0, tc)
	{
		solution(i + 1);
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

