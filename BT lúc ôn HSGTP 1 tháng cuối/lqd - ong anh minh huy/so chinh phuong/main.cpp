///bechovang

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;


bool la_snt[40005];
vector<int> mang_snt;
void sang_snt(int n){
    //memset
    for (int i=0;i<=40005;i++){
        la_snt[i]=true;
    }

    la_snt[0]=false;
    la_snt[1]=false;

    for (int i=2; i<=sqrt(n);i++){
        for (int j=i*i; j<=n; j=j+i){
            la_snt[j]=false;
        }
    }
}

using namespace std;

int mod=1e9+7;
int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    sang_snt(40000);
    for (int i=0;i<40000;i++){
        if (la_snt[i]==true)
            mang_snt.push_back(i);
    }





    return 0;
}

