#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int a[500000];
bool valid(int x, int y){

    for (int i=x+1;i<=y-1;i++){
        if (a[i]>a[x] or a[i]>a[y])
            return false;
        if (a[i]==a[x] and a[x]==a[y])
            return false;
    }

    return true;
}


signed main()
{
    faster;
    freopen("count.inp","r",stdin);
    freopen("count.ans","w",stdout);
    int n; cin>>n;

    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    int dem=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (valid(i,j)==true){
                dem++;
                cout<<i<<' '<<j<<endl;
            }
        }
    }

    cout<<dem;
    return 0;

}
