#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll n,a[1001],tg,dem;
    tg=0;
    dem=0;
    cin>>n;
    for (ll i=0;i<n;i++){
        cin>>a[i];
        tg=tg+a[i];
    }
    sort(a,a+n,greater<ll>());

    ll i=-1;
    while (dem<=tg-dem){
        i++;
        dem=dem+a[i];
    }

    cout<<i+1;
    return 0;
}
