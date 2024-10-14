#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;



int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    vector <int> a(n);
    for (auto &x : a) cin>>x;

    sort(a.begin(),a.end());

    int tg=0;
    for (int i=0;i<l-r+1;i++){
        tg+=a[i];
    }

    cout<<tg;
    return 0;
}
