#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int vuong=0;
int nhon=0;
int tu=0;
void kt_tamgiac(ll a, ll b, ll c){

    if (a*a == b*b + c*c
     or b*b == a*a + c*c
     or c*c == a*a + b*b)
        vuong++;
    else if (a*a > b*b + c*c
     or b*b > a*a + c*c
     or c*c > a*a + b*b)
        tu++;
    else
        nhon++;
}



int main()
{
    faster;
    freopen("CAU5.INP","r",stdin);
    freopen("CAU5.OUT","w",stdout);
    int n; cin>>n;
    vector <int> a(n);
    for (auto &x: a) cin>>x;
    sort(a.begin(), a.end());

//    //debug
//    for (auto x: a)
//        cout<<x<<' ';
//    cout<<endl;

    int kq=0;
    for (int i=0;i<n-2;i++){
        for (int j=i+1;j<n-1;j++){
            int tg=a[i]+a[j];
            int k=lower_bound(a.begin()+j+1, a.end(), tg) -a.begin();
            if ((k - (j+1))>0)
                for (int z=j+1;z<k;z++){
//                    cout<<a[i]<<' '<<a[j]<<' '<<a[z]<<endl;
                    kt_tamgiac(a[i], a[j], a[z]);
                }
            kq=kq+ k - (j+1);


        }
    }


//    cout<<kq<<endl;
    cout<<nhon<<' '<<vuong<<' '<<tu;

    return 0;
}
