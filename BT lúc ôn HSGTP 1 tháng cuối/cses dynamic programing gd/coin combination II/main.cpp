///BECHOVANG


#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;
int mod=1e9+7;

int main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("OUTPUT.OUT","w",stdout);
    int n; cin>>n;
    int k; cin>>k;
    int a[n+1]; //index 1
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    int dp[n+1][k+1];
    //memset
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;


    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if (j-a[i]>=0)
                dp[i][j]+=dp[i][j-a[i]];
            dp[i][j]%=mod;
        }
    }


//    //debug
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=k;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;

    cout<<dp[n][k];




    return 0;
}
