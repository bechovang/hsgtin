#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;



int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,q; cin>>n>>q;
    vector<int>a(n+1,0);
    while (q--){
        int x,y; cin>>x>>y;
        for (int i=x;i<=y;i++){
            if (a[i]==0)
                a[i]=1;
            else
                a[i]=0;
        }
    }


    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}
