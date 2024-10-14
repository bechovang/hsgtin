#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int a[100005];
int dp[100005];
vector <int> vis(100005,-1);

int memo(int x){
    if (vis[x]==true) return 0;
    vis[x]=true;
    return memo(a[x])+1;
}

signed main()
{
    faster;
//    freopen("fony.inp","r",stdin);
//    freopen("fony.out","w",stdout);
    freopen("FONY.INP","r",stdin);
    freopen("FONY.OUT","w",stdout);
    for (int i=1;i<100005;i++)dp[i]=-1;

    int n; cin>>n;

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    for (int i=1;i<=n;i++){
        for (int i=1;i<=n;i++)vis[i]=false;
        cout<<memo(i)<<endl;
    }
//    cout << "Hello world!" << endl;
    return 0;
}
