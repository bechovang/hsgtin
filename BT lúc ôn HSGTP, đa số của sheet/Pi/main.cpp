#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//★UCLN: greatest common divisor (GCD): Thuật toán Euclid
//ll gcd(ll a, ll b){
//        if (a == 0) return b;
//        gcd(b  %a, a);
//}

int gcd(int a, int b){
    if (a==0) return b;
    return gcd(b%a,a);
}


int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    while (cin>>n){
        if (n==0) break;
        int a[55], b[55];
        for (int i=0;i<n;i++){
            cin>>a[i];
        }

        int tgcap=0;
        int dem=0;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                tgcap++;
                if (gcd(a[i],a[j])==1)
                    dem++;
            }
        }
        double kq=6*tgcap;
        kq=kq/dem;
        kq=sqrt(kq);
        if (dem==0) cout<<"No estimate for this data set."<<endl;
        else cout<<fixed<<setprecision(6)<<kq<<endl;
//        cout<<tgcap<<' '<<dem<<endl;
    }


    return 0;
}
