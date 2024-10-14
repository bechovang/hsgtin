#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;


    int n;
    cin>>n;

    long long a[200005];
    memset(a,0,200005);
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=(a[i-1]+x)%n; // mod n để 2 đầu đoạn chia hết cả prefix sum là 2 số giống nhau
        if(a[i]<0) a[i]=a[i]+n;// xử lí khi gặp số âm
    }



    long long dem=0;
    long long tg;
    map <long long,int> hm;
    for (int i=0;i<=n;i++){
        if (hm[a[i]]!=0) dem=dem+hm[a[i]]; // kt nếu hm[a[i]] >0 thì từ i về trước có hm[a[i]] đoạn thỏa
        hm[a[i]]++;
    }
    cout<<dem;

    return 0;
}
