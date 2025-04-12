// [ ﷽ ] Bismillahir Rahmanir Raheem//
#include <bits/stdc++.h>
using namespace std;
#define test int t; cin >> t; while(t--)
#define N(n) int n; cin >> n;
#define ll long long
#define f(i,a,b) for(int i=int(a);i<int(b);i++)
#define fr(i,a,b) for(int i =int(a);i>int(b); i--)
#define A(a,n) vector<int> a(n); f(i,0,n) cin >> a[i];
#define pb push_back
#define bg begin()
#define ed end()
#define sz size()
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define vpi vector<pair<int,int>>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) (x.begin(), x.end())
#define YY cout << "YES\n"
#define NN cout << "NO\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define warida return

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

//https://cses.fi/problemset/task/1652

int main(){

    int m,n;
    cin >> n >> m;
    vector<vector<ll> > a(n+1,vector<ll>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x;
            cin >> x;
            if(x == '*'){
                a[i][j] = 1;
            }
            else a[i][j]=0;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j]= a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    }
    while(m--){
        ll z, b,c,d;
        cin >>z >> b >> c >>d;
        cout << a[c][d] - a[z-1][d] - a[c][b-1] + a[z-1][b-1] << endl;
    }
}