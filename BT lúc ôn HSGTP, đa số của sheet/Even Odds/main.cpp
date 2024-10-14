#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long n,k,kq;
    cin>>n>>k;

    long long le;
    if (n%2==0) le= n /2;
    else le=(n+1)/2;


    long long lecuoi;
    if (n%2==1) lecuoi=n;
    else lecuoi=n-1;

    cout<<le<<endl;
    cout<<lecuoi<<endl;

    if (k<= le){
        kq= lecuoi - (le-k)*2;
    }
    else{
        kq= (k-le)*2;
    }
    cout<<kq;
    return 0;
}
