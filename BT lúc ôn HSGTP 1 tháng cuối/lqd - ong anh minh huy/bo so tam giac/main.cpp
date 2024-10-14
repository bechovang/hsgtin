///bechovang

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

vector<int> a;

int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    int n; cin>>n;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    ll dem=0;
    for (int i=0;i<n-2;i++){
        for (int j=i+1;j<n-1;j++){
            int tg=a[i]+a[j];
            int k= lower_bound(a.begin()+j+1,a.end(),tg) - a.begin();
            dem = dem + k - (j+1);
        }
    }



    cout<<dem;
    return 0;
}
//1 3 4 5 7
