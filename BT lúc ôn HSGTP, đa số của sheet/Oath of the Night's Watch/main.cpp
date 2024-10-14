#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n,x;
    map <ll,ll> hm;
    ll lon=LLONG_MIN;
    ll nho=LLONG_MAX;
    cin >>n;
    for (ll i=0;i<n;i++){
        cin >>x;
        hm[x]++;
        lon=max(lon,x);
        nho=min(nho,x);
    }
    if (n-hm[lon]-hm[nho]<0) cout<<0;
    else cout<<n-hm[lon]-hm[nho]<<endl;
    return 0;
}
