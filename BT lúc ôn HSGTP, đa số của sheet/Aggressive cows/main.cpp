#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> a(1e5+7);

bool valid (int distance, int n, int k){
    int pre=a[0];
    int dem=1;
    for (int i=1;i<n;i++){
         if (a[i] - pre >= distance){
            dem++;
            pre=a[i];
         }
    }

    if (dem>=k) return true;
    else return false;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        a.clear();
        int n,k; cin>>n>>k;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.begin()+n);

        int l=0; int r=1e9+7;
        while (l<=r){
            int mid =  (l+r)/2;
            if (valid(mid,n,k)==false)
                r=mid-1;
            if (valid(mid,n,k)==true)
                l=mid+1;
        }
        if (valid(l,n,k)==true)
            cout<<l<<endl;
        else
            cout<<r<<endl;
//        cout<<l<<' '<<r;
    }
    return 0;
}
