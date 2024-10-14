///BECHOVANG

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;




signed main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int tg=0;
        for (int i=0;i<n;i++){
            int x; cin>>x;
            tg=tg+abs(x);
        }
        cout<<tg<<endl;
    }


    return 0;
}
