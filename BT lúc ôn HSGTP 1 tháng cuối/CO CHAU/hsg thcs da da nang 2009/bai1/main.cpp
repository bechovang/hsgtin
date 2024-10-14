#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    int dem=0;
    int tg=0;

    for (int i=1;i<=n;i++){
        if (n % i ==0){
            dem++;
            tg=tg+i;
        }
    }

    cout<<"Co tat ca "<<dem<<" uoc so"<<endl;
    cout<<"Tong cac uoc la "<<tg;


    return 0;
}


//10
//Co tat ca 4 uoc so
//Tong cac uoc la 18
