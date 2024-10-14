#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;


int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    ll n; cin>>n;
    ll a[n+1]={0};
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    ll pf[n+1]={0};
    pf[1]=a[1];
    for (int i=2;i<=n;i++){
        pf[i]=pf[i-1]+a[i];
    }

    ll kq=LLONG_MIN;
    for (int i=1;i<=n;i++){
        for (int j=n;j>=i+1;j--){
            if (a[i]==a[j]){
                kq=max(kq, pf[j]-pf[i-1]);
                break;
            }
        }
    }



//    //debug;
//    for(auto x:pf)
//        cout<<x<<' ';
//    cout<<endl;

    cout<<kq;





    return 0;
}
