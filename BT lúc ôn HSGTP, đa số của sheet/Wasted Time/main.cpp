#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

double kcach(int x1, int y1, int x2, int y2){
    return sqrt( pow( (x1-x2) ,2) + pow( (y1-y2) ,2) );
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    double k; cin>>k;

    vector<vector<int>> a(n+1, vector<int>(2));
    for (int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
//        cout<<a[i][0]<<' '<<a[i][1]<<endl;
    }

    double dem=0;
    for (int i=1;i<n;i++){
        dem=dem+kcach(a[i-1][0],a[i-1][1],a[i][0],a[i][1]);
    }

    cout<<fixed<<setprecision(9)<<dem/50 * k;
    return 0;
}

//Công thức tính khoảng cách giữa hai điểm trong hệ tọa độ hai chiều (x1, y1) và (x2, y2) là công thức khoảng cách Euclid:
//d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
