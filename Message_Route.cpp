// [ ﷽ ] Bismillahir Rahmanir Raheem
#include <bits/stdc++.h>

using namespace std;

// ========== Shortcuts ==========
#define ll long long
#define f(i,a,b) for(int i=int(a);i<int(b);i++)
#define fr(i,a,b) for(int i=int(a);i>int(b);i--)
#define test int TTT; cin >> TTT; while(TTT--)
#define cases int TTT; cin >> TTT; f(i,1,TTT+1) { cout << "Case " << i << ": ";
#define endcases }
#define A(a,n) vector<ll> a(n); f(i,0,n) cin >> a[i];
#define pb push_back
#define pii pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define mii map<ll,ll>
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

// ========== Optional Ordered Set Stuff ==========
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// // // run in terminal, cph e kaj kore na

// ========== Constants ==========
const int mod = 1e9+7;
const ll INF = LLONG_MAX;
const int inf = INT_MAX;
const double eps = 1e-9;

// ========== Functions ==========
ll inv(ll a, ll m = mod) { return a <= 1 ? a : m - (ll)(m/a) * inv(m % a, m) % m; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }
ll bigmod(ll a, ll b, ll m = mod) { if(b==0) return 1; ll x = bigmod(a,b/2,m); return (b&1)?(x*x%m)*a%m:(x*x%m); }

int main() {
    fast

    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    f(i,0,m){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int par[n+1];
    vector<bool> vis(n+1,false);
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x]=1;
        for(auto v: adj[x]){
            if(vis[v]) continue;
            q.push(v);
            par[v]=x;
            vis[v]=1;
        }
    }
    int cnt = 0;
    int cur = n;
    par[1]=0;
    if(!vis[n]){
        cout << "IMPOSSIBLE";
        return 0;
    }
    stack<int> st;
    while(cur!=0){
        st.push(cur);
        cur = par[cur];
        cnt++;
    }
    cout << cnt << endl;
    while(!st.empty()){
        cout << st.top() << " "; st.pop();
    }

}