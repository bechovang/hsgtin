#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

bool tamgiac(ll a, ll b , ll c){
    if (a+b<=c)
        return false;
    if (a+c<=b)
        return false;
    if (b+c<=a)
        return false;
    return true;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    vector<ll> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    for (int i=1;i<n-1;i++){
//        cout<<a[i-1]<<' '<<a[i]<<' '<<a[i+1]<<endl;
        if (tamgiac(a[i-1],a[i],a[i+1])==true){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
//    //debug
//    for (int i=0;i<n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;
//
//    for (auto x: st){
//        cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<endl;
//    }
    return 0;
}
