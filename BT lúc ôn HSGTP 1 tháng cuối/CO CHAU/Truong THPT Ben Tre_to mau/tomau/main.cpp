#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int n,m;
int a[105][105];
char color[105][105]={0};
bool den[105][105]={0};
int hang_X[105]={0};
int cot_X[105]={0};
int hang_V[105]={0};
int cot_V[105]={0};
int colored=0;
int need=0;

void inkq(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<color[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

bool valid(int x, int y){
    if (x<1)
        return false;
    if (y<1)
        return false;
    if (x>n)
        return false;
    if (y>m)
        return false;
    if (color[x][y]=='D')
        return false;
    if (abs(hang_V[x]-hang_X[x])>1)
        return false;
    if (abs(cot_V[y]-cot_X[y])>1)
        return false;
    return true;
}
bool valid_chenh_X(int x, int y){
    if (abs(hang_V[x] - (hang_X[x]+1) ) > 1)
        return false;
    if (abs(cot_V[y] - (cot_X[y]+1) ) > 1)
        return false;
    return true;
}
bool valid_chenh_V(int x, int y){
    if (abs(hang_X[x] - (hang_V[x]+1) ) > 1)
        return false;
    if (abs(cot_X[y] - (cot_V[y]+1) ) > 1)
        return false;
    return true;
}

void xoa_mau(int x, int y){
    if (color[x][y]=='V'){
        hang_V[x]--;
        cot_V[y]--;
    }
    if (color[x][y]=='X'){
        hang_X[x]--;
        cot_X[y]--;
    }
    colored--;
    color[x][y]='A';
    return;
}

pair<int,int> ke_tiep(int x, int y){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (color[i][j]=='A')
                return {i,j};
        }
    }
}

int quaylui(int x, int y){

    //cho no mau xanh
    if (valid(x,y)==true and valid_chenh_X(x,y)==true) {
        color[x][y]='X';
        hang_X[x]++;
        cot_X[y]++;
        colored++;
        if (colored==need) {
            inkq();
        } else {
            pair<int,int>px = ke_tiep(x,y);
            quaylui(px.first, px.second);
            xoa_mau(x,y);
        }
    }

    //cho no mau vang
    if (valid(x,y)==true and valid_chenh_V(x,y)==true) {
        color[x][y]='V';
        hang_V[x]++;
        cot_V[y]++;
        colored++;
        if (colored==need) {
            inkq();
        } else {
            pair<int,int>pv = ke_tiep(x,y);
            quaylui(pv.first, pv.second);
            xoa_mau(x,y);
        }
    }


    return 0;


}

signed main()
{
    faster;
    freopen("tomau.inp","r",stdin);
    freopen("tomau.out","w",stdout);

    cin>>n>>m;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x; cin>>x;
            if (x==1)
                color[i][j]='D';
            else{
                color[i][j]='A';
                need++;
            }

        }
    }


    //tim first
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (color[i][j]=='A'){
                quaylui(i,j);
                return 0;
            }
        }
    }




    return 0;
}

//Backtracking(k) {
//	for([Mỗi phương án chọn i(thuộc tập D)]) {
//		if ([Chấp nhận i]) {
//			[Chọn i cho X[k]];
//			if ([Thành công]) {
//				[Đưa ra kết quả];
//			} else {
//				Backtracking(k+1);
//				[Bỏ chọn i cho X[k]];
//			}
//		}
//	}
//}
