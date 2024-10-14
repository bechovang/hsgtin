#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1005][1005]={0};

int main()
{
    faster;
    freopen("VALIA.INP","r",stdin);
    freopen("VALIA.OUT","w",stdout);

    // giá trị vali phụ thuộc vào 2 yếu tố:
    // + bao nhiêu đồ vật được xét
    // + trọng lượng của đồ vật đó

    int n,k; cin>>n>>k;

    int weight[1005];
    int cost[1005];

    for (int i=1;i<=n;i++ ){
        cin>>weight[i]>>cost[i];
    }

    //memset cho dòng ko có đồ nào
    for (int j=1;j<=k;j++ )
        dp[0][j]=0;
    for (int i=1;i<=n;i++ ) // do có dp[i-1][j-weight[i]]
        dp[i][0]=0;


    //mảng 2 chiều do giá trị phụ thuộc 2 yếu tố
    for (int i=1;i<=n;i++ ){ // vật
        for (int j=1;j<=k;j++ ){ // khoang
            if (j-weight[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + cost[i]); // bỏ vào đc
                dp[i][j] = max(dp[i][j], dp[i-1][j]); //lấy ko bỏ vào lời hơn
            }

            else
                dp[i][j] = dp[i-1][j]; // ko bỏ đc
        }
    }

//    //debug
//    for(int i = 0; i <=n; i++)
//        for(int j = 1; j <= k; j++)
//            cout << dp[i][j] << " \n"[j == k];





//    int kq=-1;
//    for(int i = 0; i <=n; i++)
//        for(int j = 1; j <= k; j++)
//            kq= max(kq, dp[i][j]);
//    cout<<kq;

    cout<<dp[n][k];


    return 0;
}
