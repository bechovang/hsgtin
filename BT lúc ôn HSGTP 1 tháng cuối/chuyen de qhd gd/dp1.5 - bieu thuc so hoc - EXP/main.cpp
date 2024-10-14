#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int LimN=30000;

bool dp[505][60010];

int main()
{
    faster;
    freopen("EXP.INP","r",stdin);
    freopen("EXP.OUT","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int t; cin>>t;
    // kq của 4 hay +4 chỉ cần đổi dấu
    t=abs(t);


    //memset
//    for (int i=0;i<n;i++){
//        dp[i][0]=true;
//    }
    for (int j=1;j<=t+2;j++){
        if (a[0] == j or a[0] == j*-1 )
            dp[0][j +LimN]=true;
    }

    for (int i=1;i<n;i++){
        for (int j=0;j<=t+2;j++){
            if (dp[i-1][j - a[i] +LimN]==true or dp[i-1][j + a[i] +LimN]==true)
                dp[i][j +LimN]=true;
        }
    }


//    //debug
//    for (int i=0;i<n;i++){
//        for (int j=0;j<=t;j++){
//            cout<<dp[i][j +LimN]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;


    if (dp[n-1][t +LimN]==true)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
