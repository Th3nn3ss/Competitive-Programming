// My editorial - https://codeforces.com/blog/entry/76555?#comment-614617

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
int solution(int tc)
{
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	map<char, int> m;
	f(i, 0, n)
	{
		if(m.find(s[i]) == m.end())
			m[s[i]] = 0;
		m[s[i]]++;
	}
	string ans = "";
	if(m.size() == 1)
	{
		f(i, 0, n / k)
		{
			ans += (*m.begin()).X;
		}
		if(n % k != 0)
			ans += (*m.begin()).X;
	}
	else
	{
		if((*m.begin()).Y < k)
		{
			auto it = m.begin();
			int c = it->Y;
			while(c < k)
			{
				it++;
				c += it->Y;
			}
			ans += it->X;
		}
		else
		{
			auto it = *(m.begin());
			m[it.X] -= k;
			ans += it.X;
			if(m[it.X] == 0)
				m.erase(it.X);
			if(m.size() == 1)
			{
				int z = (*m.begin()).Y;
				f(i, 0, z / k)
				{
					ans += (*m.begin()).X;
				}
				if(z % k != 0)
					ans += (*m.begin()).X;	
			}
			else
			{
				for(auto i : m)
				{
					f(j, 0, i.Y)
					{
						ans += i.X;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 1;
}
void testCase()
{
	int tc = 1;
	cin>>tc;
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

