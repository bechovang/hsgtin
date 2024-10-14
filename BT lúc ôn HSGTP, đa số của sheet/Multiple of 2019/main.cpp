#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;

    int n=s.size();
    int pot=1; //power_of_ten
    vector <int> a(n+1,0);
    int dem=0;

    for (int i=n-1;i>=0;i--){
        int so = s[i] - '0';
//        cout<<a[dem-1]<<' '<<so<<' '<<pot<<endl;
        dem++;
        a[dem]= (a[dem-1] + (so * pot)) % 2019;
        pot = pot * 10  % 2019;
    }

    //debug
//    for (int i=0;i<=dem;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;

    map<int,int> hm;
    long long kq=0;
    for (int i=0;i<=dem;i++){
        kq=kq+hm[a[i]];
        hm[a[i]]++;
    }

    cout<<kq;
    return 0;
}
