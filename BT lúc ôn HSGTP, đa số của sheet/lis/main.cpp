#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m; cin>>n>>m;
    string s1,s2; cin>>s1>>s2;

    //chuyen thanh index-1
    s1='.'+s1;
    s2='.'+s2;

    int dp[n+1][m+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j]=max( dp[i][j-1], dp[i-1][j]); // ko chon

            if (s1[i] == s2[j]){
                dp[i][j]=dp[i-1][j-1] +1;
            }
        }
    }
//
//    //debug
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=m;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }


    cout<<dp[n][m];
    return 0;
}
