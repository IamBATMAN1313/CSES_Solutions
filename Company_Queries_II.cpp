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


const int N = 2e5+1;
int dist[N];
vector<int> adj[N];

int lift(int x, int k, const vector<vector<int> > &dp){
    while(k!=0){
        int l = k&-k;
        int r = __builtin_ctz(l);
        x = dp[x][r];
        k-=l;
    }
    if(x==0) return -1;
    return x;
}

int bin(int x, int y,  int d, const vector<vector<int> > &dp){
    if(x==y) return x;
    if(d==0) return x;
    if(d==1){
        if(x==y) return x;
        return dp[x][0];
    }
    int m = (d+1)/2;
    int a = lift(x,m-1,dp);
    int b = lift(y,m-1,dp);
    if(a==b) return bin(x,y,m-1,dp);
    int c = dp[a][0];
    int e = dp[b][0];
    if(c!=e) return bin(c,e,d/2,dp);
    return c;
}


int main() {
    fast

    int n, m;
    cin >> n >> m;
    int pw = 1;

    vector<vector<int> > dp(n+1, vector<int>(31));
    dp[1][0]=0;
    f(i,2,n+1){
        int s;
        cin >> s;
        dp[i][0] = s;
        adj[s].pb(i);
    }

    f(i,1,31){
        f(j,1,n+1){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int r = q.front();
        q.pop();
        for(int u: adj[r]){
            q.push(u);
            dist[u]= dist[r]+1;
        }
    }

    while(m--){
        int x, y;
        cin >> x >> y;
        if(dist[x]>dist[y]) swap(x,y);
        if(dist[x]==0){
            cout << x << endl;;
            continue;
        }
        y = lift(y, dist[y]-dist[x], dp);
        cout << bin(x,y,dist[x], dp) << endl;
    }
}