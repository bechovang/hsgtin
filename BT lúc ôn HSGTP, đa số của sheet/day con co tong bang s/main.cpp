#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[205][40005];

int main()
{
    faster;
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);

    int n,s; cin>>n>>s;

    int a[n];
    for (int i=1;i<=n;i++){ //index 1
        cin>>a[i];
    }

    //memset
    for (int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for (int j=1;j<=s;j++){
        if (a[1] == j)
            dp[1][j]=1;
    }

    for (int i=2;i<=n;i++){
        for (int j=1;j<=s;j++){
            if (j - a[i] >=0 and dp[i-1][j - a[i]] == 1){
                dp[i][j]=1;
            }
            else if (dp[i-1][j] == 1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }



//    //debug
//    for (int i=1;i<=n;i++){
//        for (int j=0;j<=s;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;

    if (dp[n][s] == 1)
        cout<<"YES";
    else
        cout<<"NO";


    return 0;
}
