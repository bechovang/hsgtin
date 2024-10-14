#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int dinh, canh;
int kq=0;//số lần kick mỗi nhóm
vector<vector <int>> v;
vector <int> dinhbac1;
bool end(){
    for (int i=1;i<=dinh;i++){
        if (v[i].size()==1)
            return false;
    }
    return true;
}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>dinh>>canh;

    v.resize(dinh+1);
    for (int i=0;i<canh;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    //dem cac dinh ko co bac
    int bac0=0;
    for (int i=1;i<=dinh;i++){
        if (v[i].size()==0)
            bac0++;
    }

    while (end()!=true){

        //duyet kt cac dinh bac 1
        for (int i=0;i<v.size();i++){
            if (v[i].size()==1){
                dinhbac1.push_back(i);
            }
        }

//        //debug
//        for (auto x: dinhbac1){
//            cout<<x<<' ';
//        }
//        cout<<endl;

        //xoa dinh
        for (auto x: dinhbac1){
            //xoa dinh
            for (int i=1;i<=dinh;i++){
                if (i==x){
                    v[i].clear();
                    break;
                }
            }
            //xoa canh
            for (int i=1;i<=dinh;i++){
                for (int j=0;j<v[i].size();j++){
                    if (v[i][j]==x){
                        v[i].erase(v[i].begin() + j);
                    }
                }
            }
        }

//        //debug
//        for (int i=1;i<=dinh;i++){
//            cout<<i<<": ";
//            for (int j=0;j<v[i].size();j++){
//                cout<<v[i][j]<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<endl;
        kq++; //số lần kick mỗi nhóm
    }


    cout<<kq;

}


//- xóa phần từ v[j][k] : v[j].erase(v[j].begin() + k)
