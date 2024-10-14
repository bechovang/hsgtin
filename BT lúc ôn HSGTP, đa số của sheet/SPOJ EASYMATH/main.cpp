#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
double n,m,a,d;

ll gcd(ll a, ll b){
    if (b==0) return a;
    else return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
ll soluong(ll x){
    return floor(m/x) - ceil(n/x) +1;
}
ll hop(ll a,ll b,ll c){
    return soluong(a)+soluong(b)+soluong(c)-soluong(lcm(a,b))-soluong(lcm(a,c))-soluong(lcm(b,c))-soluong(lcm(lcm(a,b),c));
}
int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t;
    cin>>t;
    for (ll o=0; o<t;o++){

        ll A,B,C,D,E;
        cin>>n>>m>>a>>d;
        A= a;
        B= a+d;
        C= a+2*d;
        D= a+3*d;
        E= a+4*d;

        ll t[100];
        t[0]= a;
        t[1]= a+d;
        t[2]= a+2*d;
        t[3]= a+3*d;
        t[4]= a+4*d;

        ll kq=soluong(A)+soluong(B)+soluong(C)+soluong(D)+soluong(E);

        for (ll i=0;i<5;i++){
            for(ll j=i+1;j<5;j++){
                kq=kq-soluong(lcm(t[i],t[j]));
//                cout<<t[i]<<' '<<t[j]<<' '<<soluong(lcm(t[i],t[j]))<<endl;
            }
        }
        for (ll i=0;i<5;i++){
            for(ll j=i+1;j<5;j++){
                for (ll z=j+1;z<5;z++){
                    kq=kq+soluong(lcm(lcm(t[i],t[j]),t[z]));
                }
            }
        }

        for (ll i=0;i<5;i++){
            for(ll j=i+1;j<5;j++){
                for (ll z=j+1;z<5;z++){
                    for (ll k=z+1;k<5;k++){
                        kq=kq-soluong(lcm(lcm(lcm(t[i],t[j]),t[z]),t[k]));
                    }
                }
            }
        }
        kq=kq+soluong(lcm(lcm(lcm(lcm(A,B),C),D),E));





        kq=m-n+1-kq;
        cout<<kq<<endl;
//        cout<<ABC+soluong(D)+soluong(E)-soluong(lcm(boiABC,D))-soluong(lcm(boiABC,E))-soluong(lcm(D,E))-soluong(lcm(lcm(boiABC,D),E))<<endl;
//        cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E<<endl;

    }

    return 0;
}

//4
//1 10 2 2
//20 100 3 3
//100 1000 4 5
//100 100000000 2 2
