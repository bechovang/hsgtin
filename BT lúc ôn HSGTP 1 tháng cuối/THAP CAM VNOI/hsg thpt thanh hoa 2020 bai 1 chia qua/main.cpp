#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
//    freopen("CAU1.INP","r",stdin);
//    freopen("CAU1.OUT","w",stdout);
    ll a,b;
    cin>>a>>b;

    ll maxx=max(a,b);
    ll minn=min(a,b);
    vector <ll> k;
    for (ll i=1;i<=sqrt(maxx);i++){
        if (maxx%i==0){
            k.push_back(i);
            if (i!=maxx/i)
                k.push_back(maxx/i);
        }
    }

    ll kq=0;
    for (auto x: k)
        if (minn%x==0)
            kq++;


    cout<<kq;
    return 0;
}
