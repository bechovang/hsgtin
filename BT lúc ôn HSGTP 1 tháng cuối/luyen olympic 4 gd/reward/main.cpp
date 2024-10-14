#include<bits/stdc++.h>
#define ll long long
#define v(a) vector<a>
using namespace std;
ll maxsum(v(ll) a, ll k, ll n)
{
    v(ll) dp(n + 1,0),prefix(n+1,0);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i-1];
    dp[0] = 0;
    for(int i = 1; i < k ; i++)
        dp[i] = prefix[i];
    for(int i = k ; i <= n; ++i)
        for(int j = i; j >= (i - k + 1); j--)
            dp[i] = max(dp[i], dp[j - 1] +
                    prefix[i] - prefix[j]);
    return dp[n];
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    v(ll) a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout<<maxsum(a,3,n);
    return 0;
}
