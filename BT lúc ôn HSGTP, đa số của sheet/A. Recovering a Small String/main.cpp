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

//    //debug
//    cout<<char(1+96)<<endl;
//    cout<<endl;

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s="";

        int k3=0;
        while (n--){
            k3++;
            if (n==2) break;
            if (char(k3+96)=='z') break;
        }
//        cout<<char(k3+96);
        s=char(k3+96)+s;


        int k2=0;
        while (n--){
            k2++;
            if (n==1) break;
            if (char(k2+96)=='z') break;
        }
//        cout<<char(k2+96);
        s=char(k2+96)+s;


//        cout<<char(n+96)<<endl;
        s=char(n+96)+s;

        cout<<s<<endl;

    }



    return 0;
}
