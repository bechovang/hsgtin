#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        double a; cin>>a;
        double k=360/(180-a);
//        cout<<k*10<<' '<<round(k)*10<<endl;
        if (k*10==round(k)*10) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
