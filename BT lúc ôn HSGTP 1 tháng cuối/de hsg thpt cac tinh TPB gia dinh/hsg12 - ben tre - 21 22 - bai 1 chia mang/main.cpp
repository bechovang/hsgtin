#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int pf[1005]={0};
int sum(int x, int y){
    return pf[y] - pf[x-1];
}

signed main()
{
    faster;
    freopen("CHIAMANG.INP","r",stdin);
    freopen("CHIAMANG.OUT","w",stdout);
    int n; cin>>n;

    for (int i=1;i<=n;i++){
        int x; cin>>x;
        pf[i]=pf[i-1]+x;
    }

    for (int i=1;i<n;i++){
        if (sum(1,i)==sum(i+1,n)){
            cout<<i;
            return 0;
        }
    }

    cout<<0;
    return 0;
}
