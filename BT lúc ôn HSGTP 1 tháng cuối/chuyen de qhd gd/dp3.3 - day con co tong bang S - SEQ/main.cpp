#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;



signed main()
{
    faster;
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    int n,k; cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    //memset
    bool dp[n+1][k+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            if (j==0) dp[i][j]=true;
            else dp[i][j]=false;
        }
    }


    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            if (dp[i-1][j]==true)//noi duoi
                dp[i][j]=true;
            if (dp[i-1][j-a[i]]==true and j-a[i]>=0) //thieu j-a[i]>=0 bị WA 1 test
                dp[i][j]=true;
        }
    }

//
//    //debug
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=k;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }

    if (dp[n][k]==true)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
