#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    int minn=INT_MAX;
    while (n--){
        int x; cin>>x;
        minn=min(minn,abs(x));
    }
    cout<<minn;
    return 0;
}
