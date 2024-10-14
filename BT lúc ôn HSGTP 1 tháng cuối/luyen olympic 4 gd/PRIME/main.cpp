///BECHOVANG


#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

vector <bool> is_prime(10000005,true);
void sang_snt(int n){
    is_prime[0]=false;
    is_prime[1]=false;

    for (int i=2;i*i<=n;i++){
        if (is_prime[i]==true){
            //di danh dau
            for (int j=i*i;j<=n;j=j+i){
                is_prime[j]=false;
            }
        }
    }
}


int main()
{
    faster;
    freopen("PRIME.INP","r",stdin);
    freopen("PRIME.OUT","w",stdout);
    sang_snt(10000000);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        if (is_prime[n]==true)
            cout<<"YES ";
        else
            cout<<"NO ";

        vector<int> kq;
        while (n>0){
            int k=n%10;
            if (is_prime[k]==true)
                kq.push_back(k);
            n=n/10;
        }

        reverse(kq.begin(),kq.end());
        if (kq.size()==0)
            kq.push_back(0);
        for (int i=0;i<kq.size();i++){
            for (int j=i+1;j<kq.size();j++){
                if (kq[j]==kq[i])
                    kq[j]=-1;
            }
        }



        for (auto x:kq)
            if (x!=-1)
                cout<<x<<' ';
        cout<<endl;

    }



    return 0;
}
