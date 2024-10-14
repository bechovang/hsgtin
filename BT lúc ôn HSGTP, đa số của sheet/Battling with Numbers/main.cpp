#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
typedef pair<int, int> pii;
const int max_n = 2e6 + 5;
const ll inf = 1e9;
const ll m_inf = -1e9;
const ll mod = 998244353;
const int base = 32;

vector<ll> f; // Mảng lưu giai thừa

//long long C(int k, int n) {
//	if (k == 0 || k == n) return 1;
//	if (k == 1) return n %998244353;
//	return (C(k - 1, n - 1)%998244353 + C(k, n - 1)%998244353 ) %998244353;
////	cout << "To hop bang: " << C(k, n);
//}

void Fac(){
    f.assign(1e5 + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= 1e5; i++){
        f[i] = (f[i - 1] * i) % mod;
    }
}

ll fastPow(ll b, int p){
    if (!b){
        return 0;
    }
    if (!p){
        return 1;
    }
    ll res = fastPow(b, p/2);
    res = (res * res) % mod;
    if (p & 1){
        res = (res * b) % mod;
    }
    return res;
}

ll C(int a, int b){
    ll res = f[a];
    res = (res * fastPow(f[b], mod - 2)) % mod;
    res = (res * fastPow(f[a - b], mod - 2)) % mod;
    return res;
}


int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int n; cin>>n;
    vector <int> a(100001);
    map <int,int> hm; // x
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        int x; cin>>x;
        hm[a[i]]=x;
    }
    int m; cin>>m;
    vector <int> b(100001);
    map <int,int> hm2; // y
    for (int i=0;i<m;i++){
        cin>>b[i];
    }
    for (int i=0;i<m;i++){
        int x; cin>>x;
        hm2[b[i]]=x;
    }

    if (n<m) swap(hm,hm2);
    map <int,int> hm3; // x trung y
    for (auto x: hm){
        if (hm2[x.first]==0 and hm[x.first]!=0){
            hm3[x.first]=hm[x.first];
        }
        else if (hm2[x.first]!=0 and hm[x.first]==0){
            hm3[x.first]=hm2[x.first];
        }
        else if (hm2[x.first]!=0 and hm[x.first]!=0){
            hm3[x.first]=abs(hm2[x.first]-hm[x.first]);
        }
    }

    int khac=0;
    for (auto x: hm3){
        if (x.second!=0)
        khac++;
    }
//    cout<<khac;

    long long kq=0;
    Fac();
    for (int i = 0; i <= khac; i++){
        kq += C(khac, i);
        kq %= mod;
    }
    cout<<kq;

//    //debug;
//    for (auto x: hm){
//        cout<<x.first<<' '<<x.second<<endl;
//    }
//    cout<<endl;
//    for (auto x: hm2){
//        cout<<x.first<<' '<<x.second<<endl;
//    }
//    cout<<endl;
//    for (auto x: hm3){
//        cout<<x.first<<' '<<x.second<<endl;
//    }
//    cout<<endl;
    return 0;
}
