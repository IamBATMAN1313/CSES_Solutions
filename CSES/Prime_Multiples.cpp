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

//https://cses.fi/problemset/task/2185

int main(){

    ll n,k;
    cin>>n>>k;
    ll a[k];
    f(i,0,k) cin>>a[i];
    ll id = (1<<k);
    ll ans=0;
    for( ll mask = 1 ; mask<id; mask++){
        ll den=n;
        ll cnt =0;
        for(int i =0 ; i<k ;i++){
            ll check = (1<<i);

            if(mask & check){
                 den/=a[i];

                cnt++;
            }
        }
        if(cnt%2==0){
            ans-=den;
        }
        else{
            ans+=den;
        }

    }
    cout<<ans<<endl;
}