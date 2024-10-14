#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k;
    cin>>n>>k;

    long long a[200005];
    memset(a,0,200005);
    map <long long,int> hm;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=a[i-1]+x;
    }



//    for (int i=0;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;
    long long dem=0;
    long long tg;
    for (int i=0;i<=n;i++){
        dem=dem+hm[a[i]-k];
        hm[a[i]]++;
    }

//    for (int i=1;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;

    cout<<dem;
    return 0;
}
// để đếm số lượng: đếm số lượng a[i]-k trước i của tất cả các i
