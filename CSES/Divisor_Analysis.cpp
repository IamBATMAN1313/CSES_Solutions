// [ ﷽ ] Bismillahir Rahmanir Raheem//
#include <bits/stdc++.h>
using namespace std;
#define test int t; cin >> t; while(t--)
#define N(n) ll n; cin >> n;
#define ll long long
#define f(i,a,b) for(int i=int(a);i<int(b);i++)
#define fr(i,a,b) for(int i =int(a);i>int(b); i--)
#define A(a,n) vector<int> a(n); f(i,0,n) cin >> a[i];
#define pb push_back
#define bg begin()
#define ed end()
#define pii pair<ll,ll>
#define vi vector<ll>
#define mii map<ll,ll>
#define vpi vector<pair<ll,ll>>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) (x.begin(), x.end())
#define YY cout << "YES\n"
#define NN cout << "NO\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define warida return
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//Comment out when ordered set needed, run in terminal instead of cph

const int mod=1e9+7;
const int INF = 2147483647;


ll inv(ll a, ll m) {
return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;}


ll bigmod(ll a, ll b, ll m){
    //a^b (mod m)
    if(b==0) return 1;
    if(b==1) return a%m;
    ll x = bigmod(a,b/2,m);
    if(b%2) return (((x*x)%m)*a)%m;
    return (x*x)%m;
}


int main(){

    fast;
    int n;
    cin >> n;
    map<ll, ll> m;
    f(i,0,n){
        ll x, k;
        cin >> x >> k;
        m[x] = k;
    }
    ll prod = 1, prod2 =1, num=1;
    for(auto it = m.begin(); it != m.end(); it++){
        num = (num*(bigmod(it->first,it->second,mod))%mod)%mod;
        prod = (prod*(it->second+1))%mod;
        prod2= (prod2*((bigmod(it->first,it->second+1,mod))-1)%mod)*inv(it->first-1,mod)%mod;
    }
    cout << prod << " "<< prod2 << " ";
    if(prod&1){
        ll z = bigmod(num, prod/2,mod);
        num = (num*inv(2,mod))%mod;
    }
    else{
        cout << bigmod(num, prod/2,mod) << " ";
    }

}