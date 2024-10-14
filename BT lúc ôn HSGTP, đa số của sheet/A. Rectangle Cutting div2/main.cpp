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
    ll t; cin>>t;
    while (t--){
        bool kq=false;
        ll k1,k2; cin>>k1>>k2;
        if (k1%2==1 and k2%2==1){
            cout<<"No"<<endl;
            continue;
        }

        ll a,b;
        if (k1%2==0){
            a=k1;
            b=k2;
        }
        else{
            a=k2;
            b=k1;
        }

        k1=a;
        k2=b;


        a=a/2;
        b=b*2;
        swap(a,b);

        if (k1!=a or k2!=b)
            kq=true;


        if (k2%2==0){
            swap(k1,k2);
            a=k1;
            b=k2;

            a=a/2;
            b=b*2;
            swap(a,b);

            if (k1!=a or k2!=b)
                kq=true;

        }


        if (kq==true)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;


    }
    return 0;
}
