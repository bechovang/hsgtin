#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll step,mod,seed[100000];
void inkq(ll step,ll mod,ll dem){
    ll lenstep=1 + floor(log10(step));
    ll lenmod=1 + floor(log10(mod));
    for (ll i=0;i<10-lenstep;i++){
        cout<<' ';
    }
    cout<<step;
    for (ll i=0;i<10-lenmod;i++){
        cout<<' ';
    }
    cout<<mod;
    for (ll i=0;i<4;i++){
        cout<<' ';
    }
    if (dem==mod) cout<<"Good Choice";
    else cout<<"Bad Choice";
    cout<<endl;
    cout<<endl;
}

int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while (cin>>step>>mod){
        ll pretmp=0;
        seed[0]=1;
        ll tmp=(pretmp + step)%mod;
        seed[tmp]=1;
        pretmp=tmp;
        while (tmp!=0){
            tmp=(pretmp + step)%mod;
            seed[tmp]=1;
            pretmp=tmp;
        }

        ll dem=0;
        for (ll i=0;i<mod;i++){
            if (seed[i]==1) dem++;
        }
//        cout<<dem<<endl;

        memset(seed,0,100000);
        inkq(step,mod,dem);
    }


    return 0;
}

//3 5
//15 20
//63923 99999
