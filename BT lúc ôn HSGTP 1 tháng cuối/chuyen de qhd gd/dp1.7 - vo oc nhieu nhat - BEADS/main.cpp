#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

signed main()
{
    faster;
    freopen("BEADS.INP","r",stdin);
    freopen("BEADS.OUT","w",stdout);
    int n; cin>>n;
    int a[n+1];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }


    int dp[n];
    deque<int> dque;
    int l=LLONG_MAX;
    int r=LLONG_MIN;


    for (int i=0;i<n;i++){
        if (a[i] > r) {
            dque.push_back(a[i]);
            r = a[i];
        } else if (a[i] < l) {
            dque.push_front(a[i]);
            l = a[i];
        } else {
            int k = lower_bound(dque.begin(), dque.end(), a[i]) - dque.begin();
            dque[k] = a[i];
        }

        r=dque[dque.size()-1];
        l=dque[0];
        dp[i] = dque.size();
    }




//    //debug
//    for (int i=0;i<n;i++) cout<<dp[i]<<' ';

    cout<<dp[n-1];
    return 0;
}


