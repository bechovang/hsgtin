#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

signed main()
{
    faster;
    freopen("SOMAYMAN.INP","r",stdin);
    freopen("SOMAYMAN.OUT","w",stdout);
    int n,t; cin>>n>>t;
    map<int,int> hm;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        hm[x]++;
    }


    while (t--){
        int x; cin>>x;
        cout<<hm[x]<<endl;
    }
    return 0;
}
