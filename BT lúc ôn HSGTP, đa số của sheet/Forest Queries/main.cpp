#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,q; cin>>n>>q;
    vector <vector <int>> a(n+1, vector<int> (n+1,0) );
    for (int i=0;i<n;i++){
        string s; cin>>s;
        for (int j=0;j<s.size();j++){
            if (s[j]=='.')
                a[i+1][j+1]=0;
            else
                a[i+1][j+1]=1;
        }
    }

    vector < vector <long long > > pf(n+1, vector<long long > (n+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            pf[i][j]=pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + a[i][j];
        }
    }

    while (q--){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        cout<<pf[x2][y2] - pf[x1-1][y2] - pf[x2][y1-1] + pf[x1-1][y1-1]<<endl;
    }

    //debug
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=n;j++){
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//
//    for (int i=0;i<=n;i++){
//        for (int j=0;j<=n;j++){
//            cout<<pf[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;


    return 0;
}
