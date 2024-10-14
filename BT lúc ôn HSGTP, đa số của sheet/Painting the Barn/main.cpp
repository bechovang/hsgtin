#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=1005;

int main()
{
    faster;
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int q,k; cin>>q>>k;

    vector < vector <int > > a(N+1, vector<int>(N+1,0));
    while (q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1++;y1++;x2++;y2++;//coordinates are dots, not cells
//        x2--;y2--;

        a[x1][y1]++;
        a[x2][y2]++;

        a[x1][y2]--;
        a[x2][y1]--;
    }

    vector < vector <int > > a(N+1, vector<int>(N+1,0));
    long long dem=0;
    for (int i=1;i<N;i++){
        for (int j=1;j<N;j++){
            pf[i][j]= a[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
            if (pf[i][j]==k) dem++;
        }
    }

    //debug
//    for (int i=0;i<=8;i++){
//        for (int j=0;j<=8;j++){
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    for (int i=0;i<=8;i++){
//        for (int j=0;j<=8;j++){
//            cout<<pf[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;

    cout<<dem<<endl;
    return 0;
}
// hệ trục tọa độ, đo theo vạch, ko phải đo theo thú tự ô
// cái ++ nằm trong HCN còn cái -- nằm ngoài làm rìa chặn của HCN
//coordinates are dots, not cells (tọa độ là nói về những điểm, ko phải ô)
