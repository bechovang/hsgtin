#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

const int LimN=3*1e3;


signed main()
{
    faster;
    freopen("STRING.INP","r",stdin);
    freopen("STRING.OUT","w",stdout);
    string a,b;
    cin>>a>>b;
    a='0'+a;
    b='0'+b;
    int N_a=a.size();
    int N_b=b.size();

    //memset
    int dp[N_a+1][N_b+1]={0};
    for (int i=0;i<N_a;i++){
        dp[i][0]=i;
    }
    for (int j=0;j<=N_b;j++){
        dp[0][j]=j;
    }

    for (int i=1;i<=N_a;i++){
        for (int j=1;j<=N_b;j++){
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) +1;
        }
    }

//    //debug
//    for (int i=0;i<=N_a;i++){
//        for (int j=0;j<=N_b;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }

    cout<<dp[N_a][N_b];

    return 0;
}
