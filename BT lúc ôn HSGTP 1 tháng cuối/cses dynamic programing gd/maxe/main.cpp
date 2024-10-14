///BECHOVANG


#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;



int main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("OUTPUT.OUT","w",stdout);
    int n; cin>>n;
    int maxx=INT_MIN;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        maxx=max(maxx,x);
    }

    cout<<maxx;


    return 0;
}
