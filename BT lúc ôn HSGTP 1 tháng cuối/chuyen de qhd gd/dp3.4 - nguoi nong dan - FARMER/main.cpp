///bechovang
#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;




signed main()
{
    faster;
    freopen("FARMER.INP","r",stdin);
    freopen("FARMER.OUT","w",stdout);
    int k, N_field, N_line; cin>>k>>N_field>>N_line;
    int n=N_field+N_line;
    vector<int> weight;
    vector<int> value;
    weight.push_back(-1); //index1
    value.push_back(-1);
    for (int i=0;i<N_field;i++){
        int x; cin>>x;
        weight.push_back(x);
        value.push_back(x);
    }
    for (int i=0;i<N_line;i++){
        int x; cin>>x;
        weight.push_back(x);
        value.push_back(x-1);
    }

    int dp[n+1][k+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            if (j-weight[i]>=0){
                dp[i][j]=max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
            }
            else
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }

    cout<<dp[n][k];

    return 0;
}
