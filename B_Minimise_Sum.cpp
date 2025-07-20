#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
     }
     if(v[1]<=v[2]){
        cout<<2*v[1]<<endl;
        return;
     }
     cout<<v[1]+v[2]<<endl;
    
       
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