#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int dp[405][405];
int inf = 1000000000;
int main()
{
    faster;
    freopen("BANTAU.INP","r",stdin);
    freopen("BANTAU.OUT","w",stdout);
    int n; cin>>n;
    int k; cin>>k;

    int a[n+1];

    for (int i=1;i<=n;i++){ //index1
        cin>>a[i];
    }



    //memset;
    for (int i=0;i<=k;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=inf;
        }
    }
    int maxx=-1;
    int tg=0;
    for (int j=1;j<=n;j++){
        maxx=max(a[j],maxx);
        dp[0][j]=maxx*j;
        tg=tg+a[j];
    }
//    for (int i=0;i<=k;i++){ // thêm cái này bị WA 40/100
//        dp[i][1]=a[1];
//    }



    for (int i=1;i<=k;i++){
        for (int j=1;j<=n;j++){
            maxx=a[j];
            for (int p=j-1;p>=0;p--){
                dp[i][j]= min(dp[i][j], dp[i-1][p] + maxx*(j-p) );
                maxx=max(maxx,a[p]);
            }
        }
    }



    //debug
    for (int i=0;i<=k;i++){
        for (int j=0;j<=n;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;



    cout<<dp[k][n]-tg;

    return 0;
}
