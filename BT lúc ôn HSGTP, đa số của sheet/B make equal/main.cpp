///BECHOVANG



#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;




int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        if (n==1){
            cin>>n;
            cout<<"YES"<<endl;
            continue;
        }



        vector <int> a(n);
        int tg=0;
        for (auto &x : a){
            cin>>x;
            tg=tg+x;
        }

        int last_high=tg/n;


        int dem=0;
        for (int i=0;i<n;i++){
            if (a[i]==last_high)
                dem++;
        }
        if (dem=n){
            cout<<"YES"<<endl;
            a.clear();
            continue;
        }


        vector <int> pf_du(n);
        pf_du[0]=max(0,a[0]-last_high);
        for (int i=1;i<n;i++){
            pf_du[i]=pf_du[i-1] + max(0,a[i]-last_high);
        }

        vector <int> pf_thieu(n);
        pf_thieu[n-1]=max(0,last_high-a[n-1]);
        for (int i=n-2;i>=0;i--){
            pf_thieu[i]=pf_thieu[i+1] + max(0,last_high-a[i]);
        }



        bool kq=false;
        for (int i=0;i<n-1;i++){
            if (pf_du[i]==pf_thieu[i+1] and pf_du[i]!=0)
                kq=true;
        }





        if (kq==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        //debug
        for (auto x:pf_du) cout<<x<<' ';
        cout<<endl;
        for (auto x:pf_thieu) cout<<x<<' ';
        cout<<endl;
        cout<<endl;

        a.clear();
        pf_du.clear();
        pf_thieu.clear();



    }

    return 0;
}
