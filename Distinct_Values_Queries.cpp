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
const int mod = 1e9+7;
const ll INF = LLONG_MAX;
const int inf = INT_MAX;
const double eps = 1e-9;

// ========== Functions ==========
ll inv(ll a, ll m = mod) { return a <= 1 ? a : m - (ll)(m/a) * inv(m % a, m) % m; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }
ll bigmod(ll a, ll b, ll m = mod) { if(b==0) return 1; ll x = bigmod(a,b/2,m); return (b&1)?(x*x%m)*a%m:(x*x%m); }


//https://cses.fi/problemset/task/1734

bool cmp(pii a, pii b){
    return a.second< b.second;
}

struct Segtree{
    int n;
    vector<int> v;
    Segtree(int x){
        n = x;
        v.resize(4*(x+1));
    }
    void add(int id,int l, int r, int at){
        if(l==r){
            v[at]=1;
            return;
        }
        int m = l+(r-l)/2;
        if(id<=m) add(id,l,m,at*2);
        else add(id,m+1,r,at*2+1);
        v[at]= v[at*2]+v[at*2+1];
    }
    void del(int id, int l, int r, int at){
        if(l==r){
            v[at]=0;
            return;
        }
        int m = l+(r-l)/2;
        if(id<=m) del(id,l,m,at*2);
        else del(id,m+1,r,at*2+1);
        v[at]= v[at*2]+v[at*2+1];       
    }
    int search(int from, int to, int l, int r, int at){
        if(from>r or to < l) return 0;
        if(from <=l and r<=to) return v[at];
        int m = l+(r-l)/2;
        int a = search(from, to, l,m,at*2);
        int b = search(from, to, m+1, r, at*2+1);
        return a+b;
    }

};

int main() {
    fast
    int n, q;
    cin >> n >> q;
    Segtree seg(n);
    vi a(n+1);
    f(i,1,n+1) cin >> a[i];
    map<int,int> last;
    vpi query , query2;
    f(i,0,q){
        int x, y;
        cin >> x >> y;
        query.pb({x,y});
        query2.pb({x,y});
    }
    //sort the queries according to the second value
    //this let's us build the array until b and perform all
    //queries upto "a b" without thinking about the rest of the arrays
    sort(ALL(query), cmp);
    map<pair<int,int>, int> ans;
    int s = 1;
    f(j,0,q){
        int r = query[j].second;
        f(i,s,r+1){
            //store the last index of each value. if we find the same value again while
            //traversing the array, we update the last index (delete the previous) and say that there is a
            //new distinct value at this index
            //this works because if the previous index is in range, the new index will be as
            // as well as our queries have a fixed right value
            if(last[a[i]]==0){
                last[a[i]]=i;
                seg.add(i,1,n,1);
            }
            else{
                seg.del(last[a[i]],1,n,1);
                seg.add(i,1,n,1);
                last[a[i]]=i;
            }
        }
        s = r+1;
        auto p = query[j];
        ans[p] = seg.search(p.first, p.second, 1,n,1);
    }
    //now output the queries in the order they appeared
    //there are better ways than creating 2 query vectors but it's easy and works
    f(i,0,q){
        cout << ans[query2[i]] << endl;;
    }
}