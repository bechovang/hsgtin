#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,a,b; cin>>n>>a; b=7-a;

    int x,y;
    bool valid=true;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        if (x==a or x==b or y==a or y==b)
            valid=false;
    }

    if (valid==true) cout<<"YES";
    else cout<<"NO";
    return 0;
}
