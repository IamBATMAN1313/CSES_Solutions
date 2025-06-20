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

// ========== Operator Overloads ==========
// Pair input
template<typename A, typename B>
istream& operator>>(istream& in, pair<A,B>& p) {
    in >> p.first >> p.second;
    return in;
}

// Vector (and nested) input
template<typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto &x : v) in >> x;
    return in;
}

// Pair output
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
    return os << p.first << ' ' << p.second;
}

// Vector (and nested) output
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << " " ;
    }
    os << endl;
    return os;
}
// ========== Ordered Set & Multiset (PBDS) ==========
template<typename T, typename Cmp = less<T>>
using ordered_set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename Cmp = less_equal<T>>
using ordered_multiset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

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

int n, m, par[510];
ll cap[510][510], netflow[510][510];
vector<int> adj[510];


//bfs on residual graph
bool bfs(int src, int snk){
    queue<int> q;
    q.push(src);
    memset(par,-1,sizeof(par));
    par[src]=0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v: adj[u]){
            if(par[v]!=-1 or cap[u][v]<=netflow[u][v]) continue;
            q.push(v);
            par[v]=u;
            if(v==snk) return true;
        }
    }
    return false;
}



ll maxflow(int src, int snk){
    ll flow = 0;
    while(bfs(src,snk)){
        int cur = snk;
        ll bottleneck =  INF;
        while(cur!=src){
            bottleneck = min(bottleneck, cap[par[cur]][cur]-netflow[par[cur]][cur]);
            cur = par[cur];
        }
        cur = snk;
        while(cur!=src){
            netflow[par[cur]][cur]+=bottleneck;
            netflow[cur][par[cur]]-= bottleneck;
            cur = par[cur];
        }
        flow+= bottleneck;
    }
    return flow;
}

//bfs on flow graph
bool bfs2(int src, int snk){
    queue<int> q;
    q.push(src);
    memset(par,-1,sizeof(par));
    par[src]=0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v: adj[u]){
            if(par[v]!=-1 or netflow[u][v]<=0) continue;
            q.push(v);
            par[v]=u;
            if(v==snk) return true;
        }
    }
    return false;
}

vector<vector<int>> paths;

void findpath(int src, int snk){
    while(bfs2(src,snk) ){
        int cur = snk;
        ll bottleneck =  INF;
        int sz = 1;
        while(cur!=src){
            bottleneck = min(bottleneck, netflow[par[cur]][cur]);
            cur = par[cur];
            sz++;
        }
        vector<int> path(sz);
        sz--;
        cur = snk;
        while(cur!=src){
            path[sz] = cur;
            sz--;
            netflow[par[cur]][cur]-=bottleneck;
            cur = par[cur];
        }
        path[0]=1;
        paths.pb(path);
    }
}

vector<bool> reachable(510);

//bfs on cut graph, identical to residual graph
bool bfs3(int src, int snk){
    queue<int> q;
    q.push(src);
    memset(par,-1,sizeof(par));
    par[src]=0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        reachable[u]=true;
        for(auto v: adj[u]){
            if(par[v]!=-1 or cap[u][v]<=netflow[u][v]) continue;
            q.push(v);
            par[v]=u;
            if(snk == v) return true;
        }
    }
    return false;
}

vector<pair<int,int>> cut;

void mincut(int src, int snk){
    bfs3(src,snk);
    for(int u=1;u<=n;u++){
        
        if(!reachable[u]) continue;
        for(auto v: adj[u]){
            if(!reachable[v]) cut.pb({u,v});
        }
    }
}


/*
maxflow(source, sink) finds maxflow from source to sink
findpath(source, sink) finds all the paths, print the bottleneck if you need the flow in that path
mincut(source, sink) finds the edges to be cut to get mincut
Don't run mincut after findpath as findpath changes the netflow graph. If needed, make a copy
*/


int main() {
    fast
    cin >> n >> m;
    f(i,0,m){
        int x,y;
        ll wt=1;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        cap[x][y]=wt;
        cap[y][x]=wt; //undirected graph
    }
    cout << maxflow(1,n) << endl;
    //findpath(1,n);
    mincut(1,n);
    for(auto p: cut) cout << p.first << " " << p.second << endl;
    for(auto p:paths){
        cout << p.size() << endl;;
        for(auto u : p) cout << u << " ";
        cout << endl; 
    }
}