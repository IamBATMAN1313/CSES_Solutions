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

//https://cses.fi/problemset/task/1640

int main(){

    int n, target;
    cin >> n >> target;
    vector<pair<ll,int> > a(n);
    f(i,0,n){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    SORT(a);
    int i = 0, j = n-1;
    ll sum = a[i].first+a[j].first;
    while(i<j){
        sum = a[i].first+a[j].first;
        if(sum==target){
            cout << a[i].second << " " << a[j].second;
            warida 0;
        }
        else if(sum>target) j--;
        else i++;
    } 
    cout << "IMPOSSIBLE";   


}