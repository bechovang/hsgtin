#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll gcd(ll a, ll b){
    if (a==0) return b;
    return gcd(b%a, a);
}


int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;


    vector <int> a(n+1,0);
    vector <int> pf(n+1,0);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    // L_i = gcd(A_1, A_2, A_3, ... A_i)
    // R_i = gcd(A_i, A_{i+1}, A_{i+1}, ..., A_n)
    vector <int> L(n+1,0);
    vector <int> R(n+1,0);

    L[0]=a[0];
    L[1]=gcd(a[0],a[1]);
    for (int i=2;i<n;i++){
        L[i]=gcd(a[i],L[i-1]);
    }

    R[n-1]=a[n-1];
    R[n-2]=gcd(a[n-1],a[n-2]);
    for (int i=n-3;i>=0;i--){
        R[i]=gcd(a[i],R[i+1]);
    }

    ll lon=LLONG_MIN;
    for (int i=0;i<n;i++){
        if (gcd(L[i-1],R[i+1])>lon)
            lon=gcd(L[i-1],R[i+1]);
    }

//    //debug
//    for (int i=0;i<n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=0;i<n;i++){
//        cout<<pf[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=0;i<n;i++){
//        cout<<L[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=0;i<n;i++){
//        cout<<R[i]<<' ';
//    }
//    cout<<endl;
//     for (int i=0;i<n;i++){
//        cout<<gcd(L[i-1],R[i+1])<<' ';
//    }
//    cout<<endl;

    cout<<lon;
}
