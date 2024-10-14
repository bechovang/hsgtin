#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool vis[501];
int tgdfs=0;
int dfs(int dinh,vector <vector<int>> v, map <int,int> w, int tg ){
    vis[dinh]=true;
    tgdfs+=w[dinh];
    for (auto x: v[dinh]){
        if (vis[x]==false){
            dfs(x,v,w,tg);
        }
    }
    return tgdfs;
}


int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ndinh,ncanh;
    int tc=1;
    while(cin>>ndinh>>ncanh){
        if (ndinh==0 and ncanh==0) break;
        cout << "Case #" << tc++ << ":\n"; //output

        map <int,int> w;
        for (int i=1;i<=ndinh;i++){
            cin>>w[i];
        }

        vector <vector<int>> vx(ndinh+1); // x-->y: lam x thi lam y
        vector <vector<int>> vn(ndinh+1); // x-->y: muon x thi phai lam y truoc
        for (int i=0;i<ncanh;i++){
            int x,y;
            cin>>y>>x; // doi lai cho de lam (doi phu thuoc thanh lam xong cai nay moi toi cai kia)
            vx[x].push_back(y);
            vn[y].push_back(x);
        }

//        //vx
//        for (int i=1;i<=ndinh;i++){
//            cout <<"vx cua "<<i<<endl;
//            for (auto x: vx[i]){
//                cout<< x<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//        //vn
//        for (int i=1;i<=ndinh;i++){
//            cout <<"vn cua "<<i<<endl;
//            for (auto x: vn[i]){
//                cout<< x<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<endl;






        //truy van
        int t; cin>>t;
        while (t--){
            int k; cin>>k;
            // earliest
            //dieu kien du de lam x: nhung tk truoc tk k
            //dfs v nguoc: x-->y: muon x thi phai lam y truoc
            tgdfs=0;
            memset(vis,false,501);
            int truock=dfs(k,vn,w,0);
            int earliest=truock;


            // latest
            // lam x cuoi cung: tong - nhung tk sau k
            // tim nhung tk sau x (ko bao gom k vi tong co k)
            // dfs v xuoi: x-->y: lam x thi lam y
            int tg=0;
            for (int i=1;i<=ndinh;i++)
                tg=tg+w[i];
            tgdfs=0;
            memset(vis,false,501);
            int sauk=dfs(k,vx,w,0)-w[k];
            int latest=tg-sauk;

            cout<<latest-earliest<<endl;


        }
        cout<<endl;
    }
    return 0;
}
