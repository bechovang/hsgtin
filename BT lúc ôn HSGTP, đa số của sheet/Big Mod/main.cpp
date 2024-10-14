#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

ll powll(ll b, ll p, ll m){
    if (p==0) return 1;
    ll sq = powll(b,p/2,m);
    sq=sq*sq;
    if (p%2==1){
        sq=sq%m * b%m; // modular
    }

    return sq%m; // modular
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll b,p,m;
    while (cin>>b>>p>>m){

        cout<<powll(b,p,m)<<endl;
    }

//    cout<<endl;
//    cout<<powll(7,5,10000);
    return 0;
}
