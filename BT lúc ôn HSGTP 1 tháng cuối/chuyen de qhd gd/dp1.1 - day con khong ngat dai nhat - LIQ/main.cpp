#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;



signed main()
{
    faster;
    freopen("LIQ.INP","r",stdin);
	freopen("LIQ.OUT","w",stdout);

	int n; cin>>n;
	int a[n];
	for (int i=0;i<n;i++) cin>>a[i];

	int dp[n];
	fill(dp, dp+n, 1);

	for (int i=0;i<n;i++){ // dp[i] là dãy con dài nhất từ 1 đến i+1, với số cuối là a[i]
        for (int j=i-1;j>=0;j--){
            if (a[j]<=a[i])
                dp[i]=max(dp[i], dp[j]+1);
        }
	}

//	//debug
//	for (int i=0;i<n;i++) cout<<dp[i]<<' ';
//	cout<<endl;


    int kq=-1;
	for (int i=0;i<n;i++) kq=max(kq,dp[i]);
	cout<<kq;

    return 0;
}
