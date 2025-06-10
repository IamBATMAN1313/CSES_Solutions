// [ ﷽ ] Bismillahir Rahmanir Raheem
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ========== Shortcuts ==========
using ll = long long;
#define f(i,a,b) for(int i=int(a);i<int(b);i++)
#define fr(i,a,b) for(int i=int(a);i>int(b);i--)
#define test int TTT; cin >> TTT; while(TTT--)
#define cases int TTT; cin >> TTT; f(i,1,TTT+1) { cout << "Case " << i << ": ";
#define endcases }
#define A(a,n) vector<ll> a(n); f(i,0,n) cin >> a[i];
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define mi map<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define mll map<ll,ll>
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

// 1) Arithmetic types
template<typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
void __print(T x) { cerr << x; }

// 2) Char, C-string, string, bool
void __print(char x)              { cerr << '\'' << x << '\''; }
void __print(const char* x)       { cerr << '"' << x << '"'; }
void __print(const std::string &x){ cerr << '"' << x << '"'; }
void __print(bool x)              { cerr << (x ? "true" : "false"); }

// 3) pair<>
template<typename T, typename V>
void __print(const std::pair<T, V> &x) { cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }

// 4) Generic containers (non-arithmetic)
template<typename T, typename std::enable_if<!std::is_arithmetic<T>::value, int>::type = 0>
void __print(const T &x) { int f=0; cerr<<'{'; for(auto &i : x) cerr<<(f++?", ":"") , __print(i); cerr<<'}'; }

// 5) _debug dispatcher
void _debug() { cerr << "]\n"; }
template<typename T, typename... V>
void _debug(T t, V... v) { __print(t); if(sizeof...(v)) cerr << ", "; _debug(v...); }

// 6) debug macro
#define debug(...) do { cerr << "LINE(" << __LINE__ << "): [" #__VA_ARGS__ "] = ["; _debug(__VA_ARGS__); } while(0)

#else
#define debug(...) do{}while(0)
#endif

// ========== Ordered Set & Multiset (PBDS) ==========
template<typename T, typename Cmp = less<T>>
using ordered_set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename Cmp = less_equal<T>>
using ordered_multiset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

// ========== Constants ==========
const ll mod   = 1e9+7;
const ll INF = LLONG_MAX;
const int inf = INT_MAX;
const double eps = 1e-9;

// ========== Functions ==========
ll inv(ll a, ll m = mod) { return a <= 1 ? a : m - (ll)(m/a) * inv(m % a, m) % m; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }
ll bigmod(ll a, ll b, ll m = mod) { if(b==0) return 1; ll x = bigmod(a,b/2,m); return (b&1)?(x*x%m)*a%m:(x*x%m); }

const ll phi   = mod - 1;      
const ll phi2 = 2 * phi;      

int main() {
    fast

    int n;
    cin >> n;

    ll numD = 1, d2 = 1;  // d mod mod, and d mod 2*phi
    bool square = true;

    map<ll,ll> factors;
    for(int i=0;i<n;i++){
        ll p,k;
        cin >> p >> k;
        factors[p] = k;
        numD = numD * (k+1) % mod;
        d2    = d2    * (k+1) % phi2;
        if(k&1) square = false;  // if any k is odd, d is even
    }

    ll sumD = 1;
    for(auto [p,k] : factors){
        ll t = (bigmod(p, k+1) + mod - 1) % mod;
        t = t * inv(p-1) % mod; 
        sumD = sumD * t % mod;
    }

    ll N = 1;
    for(auto [p,k] : factors)
        N = N * bigmod(p, k) % mod;

    // compute PRODUCT of divisors
    ll half = d2 / 2;        // floor(d/2), but mod phi it’s exact
    ll prod;
    if(!square){
        // d even ⇒ product = N^(d/2)
        prod = bigmod(N, half);
    }
    else{
        // d odd ⇒ product = N^floor(d/2) * sqrt(N)
        ll root = 1;
        for(auto [p,k] : factors)
            root = root * bigmod(p, k/2) % mod;
        prod = bigmod(N, half) * root % mod;
    }

    cout << numD << " " << sumD << " " << prod << endl;
    return 0;
}
