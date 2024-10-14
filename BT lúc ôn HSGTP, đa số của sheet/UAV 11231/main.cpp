#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll a[4000][4000];
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n=-1;
    ll m=-1;
    ll c=-1;
    while (n!=0 or m!=0 or c!=0){
        cin >>n>>m>>c;
        if (n==0 and m==0 and c==0) return 0;

        ll dem=0;
        if (c==1) dem=dem+ max(m,n) - abs(m-n) - 7 ;

        ll tc=-1;
        if (n%2==0 and c==1) tc=0;
        if (n%2==1 and c==1) tc=1;
        if (n%2==0 and c==0) tc=1;
        if (n%2==1 and c==0) tc=0;

        for (ll i=n-1;i>=8;i--){
            if (i%2==tc){
//                cout<<"i= "<<i<<endl;
                dem=dem + max(m, i) - abs(m-i) - 7 ;
            }
        }

        tc=-1;
        if (m%2==0 and c==1) tc=0;
        if (m%2==1 and c==1) tc=1;
        if (m%2==0 and c==0) tc=1;
        if (m%2==1 and c==0) tc=0;

        for (ll i=m-1;i>=8;i--){
//            cout<<"j= "<<i<<" tc: "<<tc<<endl;
            if (i%2==tc){

                dem=dem + max(n, i) - abs(n-i) - 7 ;
            }
        }

        cout<<dem<<endl;
    }

    return 0;
}

