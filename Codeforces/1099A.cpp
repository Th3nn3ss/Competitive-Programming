#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
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
int main()
{
	int w,h,u1,u2,d1,d2,ans;
	cin>>w>>h;
	cin>>u1>>d1;
	cin>>u2>>d2;
	ans=w;
	fre(i,h,1)
	{
		ans+=i;
		if(i==d1)
		{
			ans-=u1;
			if(ans<0)
				ans=0;
		}
		if(i==d2)
		{
			ans-=u2;
			if(ans<0)
				ans=0;
		}
	}	
	cout<<ans;
}