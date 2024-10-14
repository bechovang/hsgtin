#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

const int LimN=5*1e6;

char s[LimN+5];
bool la_snt[LimN+5];

void sang_snt(int n){
    la_snt[0]=false;
    la_snt[1]=false;
    for (int i=2;i*i<=n;i++){
        if (la_snt[i]==true)
        for (int j=i*i;j<=n;j=j+i){
            la_snt[j]=false;
        }
    }
    return ;
}

bool kt_snt(int n){
    if (n==0) return false;
    if (n==1) return false;
    if (n<LimN) return la_snt[n];
    for (int i=2; i*i<=n;i++){
        if (n%i==0)
            return false;
    }
    return true;
}

bool la_chu(char k){
    if (k>='0' and k<='9')
        return false;
    return true;
}
bool la_so(char k){
    if (la_chu(k)==true)
        return false;
    return true;
}


signed main()
{
    faster;
    freopen("NTMAX.INP","r",stdin);
    freopen("NTMAX.OUT","w",stdout);
    for (int i=0;i<=LimN+5;i++) la_snt[i]=true;
    sang_snt(LimN+5);

    cin>>s;
    int sz;
    string chu;
    string so;


    int kq=0;

    for (int i=0;i<=LimN+5;i++){
        if (s[i]=='\0'){
            sz=i;
            break;
        }


        if (la_chu(s[i])==true)
            chu=chu+s[i];
        if (la_so(s[i])==true)
            so=so+s[i];


        if ((la_chu(s[i])==true and so!="")
            or (la_so(s[i])==true and s[i+1]=='\0')){
            int k=stoi(so);
            if (kt_snt(k))
                kq=max(kq,k);
            so="";
        }
    }


//    cout<<chu<<endl;
//    cout<<so<<endl;
//
//
//    cout<<s<<' '<<sz<<endl;


    cout<<sz-chu.size()<<endl;
    cout<<kq;
    return 0;
}

