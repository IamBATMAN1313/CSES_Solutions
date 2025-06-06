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

//https://cses.fi/problemset/task/2165

int main(){

    int n;
    cin >> n;
    ll x = 1<<n;
    int small = 1;
    stack<int> q1,q2,q3;
    f(i,1,n+1) q1.push(i);
    cout << x-1 << endl;
    if(n&1){
        f(i,1,x){
            if(i&1){
                
                if(small==1){
                    q1.pop();
                    cout <<1 << " " << 3 << endl;
                    q3.push(1);
                    small = 3;
                }
                else if(small==2){
                    q2.pop();
                    cout << 2 << " " << 1 << endl;
                    q1.push(1);
                    small = 1;
                }
                else if(small==3){
                    q3.pop();
                    cout << 3 << " " << 2 << endl;
                    q2.push(2);
                    small = 2;
                }
            }
            else{
                if(small ==1){
                    int x = (q2.empty())? INF: q2.top();
                    int y = (q3.empty())? INF: q3.top();
                    if(x<y){
                        q2.pop();
                        cout << 2 << " " << 3 << endl;
                        q3.push(x);
                    }
                    else{
                        q3.pop();
                        cout << 3 << " " << 2 << endl;
                        q2.push(y);
                    }
                }
                else if(small == 2){
                    int x = (q1.empty())? INF: q1.top();
                    int y = (q3.empty())? INF: q3.top();
                    if(x<y){
                        q1.pop();
                        cout << 1 << " " << 3 << endl;
                        q3.push(x);
                    }
                    else{
                        q3.pop();
                        cout << 3 << " " << 1 << endl;
                        q1.push(y);
                    }
                }
                else if(small == 3){
                    int x = (q1.empty())? INF:q1.top();
                    int y = (q2.empty())? INF: q2.top();
                    if(x<y){
                        q1.pop();
                        cout << 1 << " " << 2 << endl;
                        q2.push(x);
                    }
                    else{
                        q2.pop();
                        cout << 2 << " " << 1 << endl;
                        q1.push(y);
                    }
                }
            }
        }
    }
    else{
    f(i,1,x){
        if(i&1){     
            if(small==1){
                q1.pop();
                cout <<1 << " " << 2 << endl;
                q2.push(1);
                small = 2;
            }
            else if(small==2){
                q2.pop();
                cout << 2 << " " << 3 << endl;
                q3.push(1);
                small = 3;
            }
            else if(small==3){
                q3.pop();
                cout << 3 << " " << 1 << endl;
                q1.push(1);
                small = 1;
            }
        }
        else{
            if(small ==1){
                int x = (q2.empty())? INF: q2.top();
                int y = (q3.empty())? INF: q3.top();
                if(x<y){
                    q2.pop();
                    cout << 2 << " " << 3 << endl;
                    q3.push(x);
                }
                else{
                    q3.pop();
                    cout << 3 << " " << 2 << endl;
                    q2.push(y);
                }
            }
            else if(small == 2){
                int x = (q1.empty())? INF: q1.top();
                int y = (q3.empty())? INF: q3.top();
                if(x<y){
                    q1.pop();
                    cout << 1 << " " << 3 << endl;
                    q3.push(x);
                }
                else{
                    q3.pop();
                    cout << 3 << " " << 1 << endl;
                    q1.push(y);
                }
            }
            else if(small == 3){
                int x = (q1.empty())? INF:q1.top();
                int y = (q2.empty())? INF: q2.top();
                if(x<y){
                    q1.pop();
                    cout << 1 << " " << 2 << endl;
                    q2.push(x);
                }
                else{
                    q2.pop();
                    cout << 2 << " " << 1 << endl;
                    q1.push(y);
                }
            }
        }
    }
}
}