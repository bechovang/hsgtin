#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

ll gcd(ll a,ll b){
    if (a==0) return b;
    gcd(b %a, a);
}

bool ktcapsnt(ll a, ll b){
    if (gcd(a,b)==1) return true;
    else return false;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll l,r;
    cin>>l>>r;
    for (ll i=l;i<=r;i++){
        for (ll j=i+1;j<=r;j++){
            for (ll z=j+1;z<=r;z++){
                if ( ktcapsnt(i,j)==true and ktcapsnt(j,z)==true and ktcapsnt(z,i)==false ){
                    cout<<i<<' '<<j<<' '<<z<<endl;
                    return 0;
                }

            }
        }
    }

    cout<<-1;
    return 0;
}


//★UCLN: greatest common divisor (GCD): Thuật toán Euclid
//ll gcd(ll a, ll b){
//        if (a == 0) return b;
//        gcd(b  %a, a);
//}
