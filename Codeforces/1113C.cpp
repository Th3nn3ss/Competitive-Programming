#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
long ve[1048578] = {}, vo[1048578] = {};
int main()
{
	long n, inp, pre;
	ll ans = 0;
	cin>>n;
	vl v;
	v.pb(0);
	f(i,0,n)
	{
		scanf("%ld",&inp);
		v.pb(inp);
	}
	long x = v[0];
	ve[0]++;
	f(i, 1, n+1)
	{
		pre = x ^ v[i];
		if(i % 2 ==0)
		{
			ans += ve[pre];
			ve[pre]++;
		}
		else
		{
			ans += vo[pre];
			vo[pre]++;
		}
		// cout<<ans<<" ";
		x = pre;
	}
	// cout<<endl;
	cout<<ans<<endl;
} 