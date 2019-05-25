#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long,long> pl;
typedef set<int> si;
typedef set<long> sl;
typedef multiset<int> msi;
typedef multiset<long> msl;
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
#define all(v) beg(v), en(v)
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
const long MOD = 998244353;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    string s[n];
    f(i, 0, n/2)
    {
    	f(j, 0, (n-(i*2+1))/2)
    		s[i]+='*';
    	f(j, 0, i*2+1)
    		s[i]+='D';
    	f(j, 0, (n-(i*2+1))/2)
    		s[i]+='*';
    	cout<<s[i]<<endl;
    }
    f(i, 0, n)
    	cout<<'D';
    cout<<endl;
    fre(i, n / 2 - 1, 0)
    	cout<<s[i]<<endl;

}  