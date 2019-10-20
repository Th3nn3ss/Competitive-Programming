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
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
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
#define fi first
#define se second
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
vi getDivisors(int n)
{
	int s = sqrt(n);
	vi ans;
	fe(i, 1, s)
	{
		if(!(n % i))
		{
			ans.pb(i);
			if(i != (n/i))
				ans.pb(n / i);
		}
	}
	return ans;
}
ll solution(int t)
{
	int m, n, q, p, r;
	cin>>n>>m>>q;
	vi ans(n + 1);
	ll final = 0;
	fe(i, 1, n)
	{
		ans[i] = (n / i);
		// cout<<i<<" "<<ans[i]<<endl;
	}
	f(i, 0, m)
	{
		cin>>p;
		vi divisors = getDivisors(p);
		f(j, 0, divisors.size())
		{

			ans[divisors[j]] -= 1;
			// cout<<divisors[j]<<" "<<ans[divisors[j]]<<" ";
		}
		// cout<<endl;
	}
	f(i, 0, q)
	{
		cin>>r;
		final += (ll)ans[r];
	}
	return final;
}
void testCase()
{
	int t = 1;
	cin>>t;
	f(i, 0, t)
	{
		cout<<"Case #"<<i+1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}  
