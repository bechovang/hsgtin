#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<int>>a(2000+1, vector<int>(2000+1,0));

int ktngang(int x, int y){
    x--; y--; // chuyển về index 0 cho giống mảng a
    if (a[x][y]==1 and a[x][y+1]==1)
        return 1;
    else
        return 0;
}
int ktdoc(int x, int y){
    x--; y--; // chuyển về index 0 cho giống mảng a
    if (a[x][y]==1 and a[x+1][y]==1)
        return 1;
    else
        return 0;
}


int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,q; cin>>n>>m>>q;

//    // nhập mảng a <=> nhập đề
//    vector<vector<int>>a(n+1, vector<int>(m+1,0));
    for (int i=0;i<n;i++){
        string s; cin>>s;
        for (int j=0;j<m;j++){
            if (s[j]=='1') a[i][j]=1;
            else a[i][j]=0;
        }
    }

// các mảng đều là prefix hết trừ mảng a, mảng prefix đi từ 1 để ko bị out
    // tạo mảng prefix số lượng ô chữ số 1
    vector<vector<int>>slo(n+1, vector<int>(m+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            slo[i][j] = a[i-1][j-1] // tại mảng a đi từ 0
                        + slo[i-1][j]
                        + slo[i][j-1]
                        - slo[i-1][j-1] ;
        }
    }

    // tạo mảng prefix số lượng ô số 1 kề ngang
    vector<vector<int>>ngang(n+1, vector<int>(m,0)); // N x (M-1)
    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            ngang[i][j] = ktngang(i,j) // tại mảng a đi từ 0
                        + ngang[i-1][j]
                        + ngang[i][j-1]
                        - ngang[i-1][j-1] ;
        }
    }

    // tạo mảng prefix số lượng ô số 1 kề dọc
    vector<vector<int>>doc(n, vector<int>(m+1,0)); // (N-1) x M
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            doc[i][j] = ktdoc(i,j) // tại mảng a đi từ 0
                        + doc[i-1][j]
                        + doc[i][j-1]
                        - doc[i-1][j-1] ;
        }
    }

////debug mảng
//
//    for (int i=0;i<n;i++){
//        for (int j=0;j<m;j++){
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++){
//            cout<<slo[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<m;j++){
//            cout<<ngang[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//
//    for (int i=1;i<n;i++){
//        for (int j=1;j<=m;j++){
//            cout<<doc[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;

    while (q--){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        // số vùng liên thông = số lượng - số liên kết
        cout<< slo[x2][y2] - slo[x1-1][y2] - slo[x2][y1-1] + slo[x1-1][y1-1]
             - (ngang[x2][y2-1] - ngang[x1-1][y2-1] - ngang[x2][y1-1] + ngang[x1-1][y1-1])
             - (doc[x2-1][y2] - doc[x1-1][y2] - doc[x2-1][y1-1] + doc[x1-1][y1-1]) << endl;
    }
    return 0;
}
