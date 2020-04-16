#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define x first
#define y second
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
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}   
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
int dp(vector<vector<bool>> &DP, vector<vector<char>> &a, int &n, int r, int c)
{
	// cout<<r<<" "<<c<<endl;
	if(DP[r][c])
		return 0;
	DP[r][c] = 1;
	fe(z, r - 1, r + 1)
	{
		if(z >= 0 && z < 3)
		{
			int flag = 0;
			f(i, c, min(n, c + 4))
			{
				if(a[z][i] == '.' || a[z][i] == 's')
					continue;
				flag = 1;
				break;
			}
			if(flag == 0)
			{
				if(c + 3 < n - 1)
				{
					if(dp(DP, a, n, z, c + 3))
						return 1;
				}
				else
					return 1;
			}
		}
	}
	return 0;
}
void solution(int t)
{
	int n, k, s;
	cin>>n>>k;
	vector<vector<char>> a(3, vector<char>(n));
	f(i, 0, 3)
	{
		f(j, 0, n)
		{
			cin>>a[i][j];
		}
	}
	f(i, 0, 3)
	{
		if(a[i][0] == 's')
		{
			s = i;
		}
	}
	if(a[s][1] != '.')
	{
		cout<<"NO"<<endl;
		return;
	}
	vector<vector<bool>> DP(3, vector<bool>(n, 0));
	if(dp(DP, a, n, s, 1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
void testCase()
{
	int t = 1;
	cin>>t;
	f(i, 0, t)
	{
		solution(i + 1);
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   
