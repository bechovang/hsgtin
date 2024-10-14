#include <bits/stdc++.h>

using namespace std;
#define endl '/n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;

    int contest[105]={0};
    int gym[105]={0};
    int dp[105][3]={0};//0: nghi, 1:contest, 2:gym
    int inf=INT_MAX;
    for (int i=1;i<=n;i++){
        int x; cin>>x;
        if (x==0){
            dp[i][0]=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) +1;
            dp[i][1]=inf;
            dp[i][2]=inf;
        }
        else if (x==1){
            dp[i][0]=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) +1;
            dp[i][1]=min(dp[i-1][0], dp[i-1][2]);
            dp[i][2]=inf;
        }
        else if (x==2){
            dp[i][0]=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) +1;
            dp[i][1]=inf;
            dp[i][2]=min(dp[i-1][0], dp[i-1][1]);
        }
        else if (x==3){
            dp[i][0]=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) +1;
            dp[i][1]=min(dp[i-1][0], dp[i-1][2]);
            dp[i][2]=min(dp[i-1][0], dp[i-1][1]);
        }
    }


    cout<<min({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}
