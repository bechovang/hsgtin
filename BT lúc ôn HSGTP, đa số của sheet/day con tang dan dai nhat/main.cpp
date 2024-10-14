// bechovang

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
    int a[n+1];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }


    int dpsubset[n+1];
    for (int i=0;i<n;i++){
        dpsubset[i]=1;
    }

    for (int i=0;i<n;i++){
        for (int j=i;j>=0;j--){
            if (a[j]<a[i]){
                dpsubset[i]=max(dpsubset[i], dpsubset[j] + 1 ); //bước chọn
            }
        }
    }


    int maxx=-1;;
    for (int i=0;i<n;i++){
        maxx=max(maxx,dpsubset[i]);
    }

//
//    //debug
//    for (int i=0;i<n;i++){
//        cout<<dpsubset[i]<<' ';
//    }

    cout<<maxx<<endl;

    return 0;
}

//5
//1 3 2 2 5
//4
