// [ ﷽ ] Bismillahir Rahmanir Raheem//
#include <bits/stdc++.h>
using namespace std;
#define test int t; cin >> t; while(t--)
#define f(i,a,b) for(int i=int(a);i<int(b);i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//https://cses.fi/problemset/task/1163


int main(){
    fast;

    int p, n;
    cin >> p >> n;
    set<int> s;
    s.insert(0);
    s.insert(p);
    multiset<int> diff;
    diff.insert(p);
    f(i,0,n){
        int x;
        cin >> x;
        auto r = s.upper_bound(x);
        auto l = r;
        l--;
        diff.erase(diff.find(*r-*l));
        diff.insert(*r-x);
        diff.insert(x-*l);
        s.insert(x);
        auto z = diff.end();
        z--;
        cout << *z << " ";
    }
}