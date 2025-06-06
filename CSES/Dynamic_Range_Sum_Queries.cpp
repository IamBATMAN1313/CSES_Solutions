// [ ﷽ ] Bismillahir Rahmanir Raheem//
#include <bits/stdc++.h>
using namespace std;
#define test ll t; cin >> t; while(t--)
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


//https://cses.fi/alon/task/1648

struct fenwick{
    ll n;
    vector<ll> v, tree;
    fenwick(ll n){
        this->n = n;
        v.resize(n+1);
        tree.resize(n+1);
        f(i,1,n+1){
            cin >> v[i];
            build(i);
        }
    }
    void build(ll i){
        ll j = i & (-i);
        ll sum=0;
        for(ll k =i; k>i-j; k--)
        {
            sum+=v[k];
        }
        tree[i]=sum;
    }
    ll sum_(ll n){
        ll sum = 0;
        while(n>0){
            sum+=tree[n];
            ll z = n & (-n);
            n = n-z;
        }
        return sum;
    }
    ll query(ll l, ll r){
        return sum_(r)- sum_(l-1);
    }

    void update(ll ind , ll val){
        ll cng = val - v[ind];
        v[ind] = val;

        while(ind <= n){
            tree[ind]+=cng;
            ll z = ind & (-ind);
            ind = ind + z;
        }
    }
};

int main(){
    ll n, q;
    cin >> n >> q;
    fenwick ft(n);
    while(q--){
        ll x,y,z;
        cin >> x >> y >> z;
        if(x==1){
            ft.update(y,z);
        }
        else{
            cout << ft.query(y,z) << endl;;
        }
    }
}