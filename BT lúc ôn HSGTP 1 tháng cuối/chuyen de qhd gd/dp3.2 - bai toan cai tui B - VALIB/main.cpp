#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;



signed main()
{
    faster;
    freopen("VALIB.INP","r",stdin);
    freopen("VALIB.OUT","w",stdout);
    int n,k; cin>>n>>k;
    int weight[n+1];
    int value[n+1];
    for (int i=1;i<=n;i++){
        cin>>weight[i]  ;
        cin>>value[i];
    }


    //memset
    //=> hàng 0, cột 0 =0
    int dp[n+1][k+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }

    for (int i=1;i<=n;i++){ // đi từ 1 nên i-1 luôn >=0
        for (int j=1;j<=k;j++){
            if (j-weight[i]>=0){
                dp[i][j]= max(dp[i][j], dp[i][j-weight[i]]+value[i]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            else
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }


    cout<<dp[n][k];


    return 0;
}
