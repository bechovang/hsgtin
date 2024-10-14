#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,x;
    map <ll,ll> hm;
    set <ll> sorthm;
    cin>>n;
    for (ll i=0;i<n;i++){
        cin>>x;
        hm[x]=i+1;
    }
    for (ll i=1;i<=n;i++){
        cout<<hm[i]<<' ';
    }

    return 0;
}
