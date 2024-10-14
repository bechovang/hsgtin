#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,l,r; cin>>a>>b>>l>>r;

    // đánh dấu khung giờ của Z
    int time[10000]={0};
    for (int i=0;i<a;i++){
        int x,y; cin>>x>>y;
        for (int j=x;j<=y;j++){
            time[j]=1;
        }
    }

    // lưu lại khung giờ của X
    vector <pair<int,int>> v;
    for (int i=0;i<b;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }

    // thử hết các giá trị t (thời gian X thức dậy)
    int dem=0;
    for (int k=l;k<=r;k++){
        bool check=false;
        for (auto x:v){
            int dau=x.first + k;
            int cuoi=x.second + k;
            for (int i=dau;i<= cuoi; i++){
                if (time[i]==1){
                    check=true;
                    break;
                }
            }
            if (check==true){
                dem++;
                break;
            }
        }
    }

    cout<<dem;
    return 0;
}
