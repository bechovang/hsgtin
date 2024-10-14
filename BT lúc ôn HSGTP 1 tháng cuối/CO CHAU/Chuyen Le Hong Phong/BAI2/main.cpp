#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

vector <vector<int>>dp(100000,vector<int>(300000));
int a[100005];

signed main()
{
    faster;
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    int n; cin>>n;

    int maxx=INT_MIN;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(a[i],maxx);
    }

    //memset
    for (int i=0;i<1005;i++){
        for (int j=0;j<305;j++){
            if (i==a[1]) dp[i][j]=1;
            else dp[i][j]=0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=i-1;j>=1;j--){
            if (a[i]-a[j]<1) continue;
            int k=a[i]-a[j];
            dp[a[i]][k] = dp[a[j]][k] + 1;

        }
    }


    for (int i=1;i<=90;i++){
        for (int j=1;j<=90;j++){
            cout<<dp[j][i]<<' ';
        }
        cout<<endl;
    }



    return 0;
}
