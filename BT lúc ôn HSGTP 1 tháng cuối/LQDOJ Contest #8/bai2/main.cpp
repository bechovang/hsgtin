#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);

    int n;
    cin>>n;

    vector<ll> a;
    for (int i=0;i<n;i++){
        ll x;cin>>x;
        a.push_back(x);
    }



    ll kq=LLONG_MAX;
    for (int i=0;i<n;i++){
        ll m=a[i];
        ll tg=0;
        for (int j=0;j<n;j++){
            tg=tg+ pow(a[j]-m,2);
        }

        kq=min(kq,tg);
    }
    cout<<kq;
    return 0;
}
