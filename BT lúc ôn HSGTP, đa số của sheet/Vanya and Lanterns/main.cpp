#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    double l;
    cin>>n>>l;

    //nhập mảng và sort
    int a[1005];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    double maxx=-(10e9+1);
    for (int i=0;i<n;i++){

        double k;
        if (i==0)
            k=a[i]; // THĐB: đoạn ở ngoài cùng bên trái
        else
            k=(a[i]-a[i-1])/2.0; // tìm bán kính chiếu sáng ở giữa 2 đèn

        maxx=max(maxx,k);

    }

    maxx=max(maxx,(l-a[n-1])); // THĐB: đoạn ở ngoài cùng bên phải
    cout<<fixed<<setprecision(9)<<maxx; // in kq sai số ko vượt quá 10^-9
    return 0;
}
