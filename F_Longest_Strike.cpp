#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
 ll n,k;
 cin>>n>>k;
 
 map<ll,ll>mp;
 ll mx=0;
 ll mn=LLONG_MAX;
 for(ll i=0;i<n;i++) {
    ll x;
    cin>>x;
    mx = max(mx, x);
    mn = min(mn, x);
    mp[x]++;
    }
   // cout<<mn<<" "<<mx<<endl;
    
    ll ansl=-1,l=mn, r=mn,ansr=-1;
    ll mxsz=0;
    vector<ll>v;
    for(auto it:mp) {
        v.pb(it.first);
    }
    while(r<=mx) {
        if(  mp[r]<k){
            ll ind=upper_bound(v.begin(), v.end(), r) - v.begin();
            if(ind == v.size()) {
                break;
            }
            l=v[ind];
            r=l;
            
        }
        else{
            r++;
            if(r-l >mxsz) {
                mxsz = r-l;
                ansl = l;
                ansr = r;
            }
            
        }  
    }
    if(ansl == -1) {
        cout<<-1<<endl;
    } 
    else {
        cout<<ansl<<" "<<ansr-1<<endl;
    }
    
       
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
     cin >> t; // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}