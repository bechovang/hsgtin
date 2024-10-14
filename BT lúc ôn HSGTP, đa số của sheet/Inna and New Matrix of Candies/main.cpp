#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // nhập input
    int n,m; cin>>n>>m;
    char s[1005][1005];
    for (int i=0;i<n;i++){
        cin>>s[i]; // do inp ko có dấu cách
    }

    set <int> kcach; // có chức năng sắp xếp và bỏ những cái trùng
    for (int i=0;i<n;i++){
        int vtG=-1;
        int vtS=-1;
        for (int j=0;j<m;j++){
            if (s[i][j]=='G')
                vtG=j;
            if (s[i][j]=='S'){ //gặp S là dừng
                vtS=j;
                break;
            }
        }
        if (vtG==-1 or vtS==-1){ // ko thấy Dwarf hoặc kẹo
            cout<<-1;
            return 0;
        }
        kcach.insert(vtS-vtG); // thêm khoảng cách vào
    }

    cout<<kcach.size();


    return 0;
}
