///BECHOVANG

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;




signed main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int tg=0;
        vector <int>a;
        for (int i=0;i<n;i++){
            int x; cin>>x;
            a.push_back(x%3);
            tg=tg+x;
        }
        sort(a.begin(), a.end());


//        cout<<tg%3<<":   ";
        if (tg%3==0){
            cout<<0;
        }
        else if (binary_search(a.begin(),a.end(),tg%3)==1)
            cout<<1;
        else{
            if ((tg+1) % 3==0){
                cout<<1;
            }
            else if ((tg+2) % 3==0){
                cout<<2;
            }
        }

//        //debug
//        cout<<":    ";
//        for (auto x: a) cout<<x<<' ';



        cout<<endl;
    }


    return 0;
}
