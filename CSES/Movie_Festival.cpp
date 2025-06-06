// [ ﷽ ] Bismillahir Rahmanir Raheem

#include <bits/stdc++.h>
using namespace std;

// ========== Shortcuts ==========
#define ll long long
#define f(i,a,b) for(int i=int(a);i<int(b);i++)
#define fr(i,a,b) for(int i=int(a);i>int(b);i--)
#define test int t; cin >> t; while(t--)
#define cases int t; cin >> t; f(i,1,t+1) { cout << "Case " << i << ": ";
#define endcases }
#define A(a,n) vector<ll> a(n); f(i,0,n) cin >> a[i];
#define pb push_back
#define pii pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define mii map<ll,ll>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) (x).begin(), (x).end()
#define YY cout << "YES\n"
#define NN cout << "NO\n"
#define endl "\n"
#define setbit(x,k) ((x) | (1LL<<(k)))
#define clrbit(x,k) ((x) & ~(1LL<<(k)))
#define checkbit(x,k) (((x)>>(k))&1)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); cout << fixed << setprecision(10);
#define warida return

// ========== Debugging ==========
#ifndef ONLINE_JUDGE
template<typename T>
typename enable_if<is_arithmetic<T>::value>::type __print(T x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V> void __print(const pair<T, V> &x) {
    cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';
}
template<typename T> void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
    cerr << '}';
}
void _debug() { cerr << "]\n"; }
template<typename T, typename... V>
void _debug(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _debug(v...); }

#define debug(...) cerr << "LINE(" << __LINE__ << "): [" << #__VA_ARGS__ << "] = ["; _debug(__VA_ARGS__)
#else
#define debug(...)
#endif

// ========== Optional Ordered Set Stuff ==========
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// //comment out when ordered set needed, run in terminal instead of cph

// ========== Constants ==========
const int mod = 1e9+7;
const long long int INF = __LONG_LONG_MAX__;
const int inf = INT_MAX;
const double eps = 1e-9;

// ========== Functions ==========

ll inv(ll a, ll m=mod) {return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll bigmod(ll a, ll b, ll m=mod){
    //a^b (mod m)
    if(b==0) return 1;
    if(b==1) return a%m;
    ll x = bigmod(a,b/2,m);
    if(b%2) return (((x*x)%m)*a)%m;
    return (x*x)%m;
}

//https://cses.fi/problemset/task/1629/
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
   return a.second < b.second;
}

int main(){
    fast
    ll n;
    cin >> n;
    ll ans = 1;
    vector<pair<ll,ll> > a(n);
    f(i,0,n){
        cin >> a[i].first >> a[i].second;
    }
    sort(ALL(a), cmp);
    ll now = a[0].second;
    f(i,1,n){
        if(a[i].first>=now){
            ans++;
            now = a[i].second;
        }
    }
    cout << ans << endl;
}