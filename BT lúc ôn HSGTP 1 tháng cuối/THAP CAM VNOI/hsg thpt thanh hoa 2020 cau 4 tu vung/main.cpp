#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

bool la_nguyen_am(char k){
    if (k=='a'
    or k=='e'
    or k=='i'
    or k=='o'
    or k=='u')
        return true;
    return false;
}
bool la_phu_am(char k){
    if (la_nguyen_am(k)==true)
        return false;
    else
        return true;
}

int main()
{
    faster;
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    string s;
    cin>>s;
    s='_'+s; //index1
    int n=s.size()-1;

    int pf_nguyen_am[n+1]={0};
    pf_nguyen_am[1]=la_nguyen_am(s[1]);
    for (int i=2;i<=n;i++){
        pf_nguyen_am[i]= pf_nguyen_am[i-1] + la_nguyen_am(s[i]);
    }


    int pf_phu_am[n+1]={0};
    pf_phu_am[1]=la_phu_am(s[1]);
    for (int i=2;i<=n;i++){
        pf_phu_am[i]= pf_phu_am[i-1] + la_phu_am(s[i]);
    }

    int kq=0;
    for (int i=1;i<=n;i++){
        if (la_nguyen_am(s[i])==true)
            kq=kq+ (pf_phu_am[n] - pf_phu_am[i-1]);
    }
    for (int i=1;i<=n;i++){
        if (la_phu_am(s[i])==true)
            kq=kq+ (pf_nguyen_am[n] - pf_nguyen_am[i-1]);
    }

    cout<<kq;


//    //debug
//    for (auto x: pf_nguyen_am)
//        cout<<x<<' ';
//    cout<<endl;
//
//    for (auto x: pf_phu_am)
//        cout<<x<<' ';
//    cout<<endl;


    return 0;
}
