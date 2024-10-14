#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
string k;
int kthuc=0;


int dem(string b){
    int d=0;
    for (int i=0;i<b.size();i++){
        if (b[i]=='+')
            d++;
        else
            d--;
    }
    return d;
}

char a[10000];
int dung=0;
int dfs(int i){
    if (k[i]=='+'){ // nếu là dấu + => giữ lại => 1TH
        a[i]='+';
        dfs(i+1);
        return 0;
    }
    if (k[i]=='-'){ // nếu là dấu - => giữ lại => 1TH
        a[i]='-';
        dfs(i+1);
        return 0;
    }
    if (k[i]=='?'){ // nếu là dấu ? => + / - => 2TH
        a[i]='+';
        dfs(i+1);

        a[i]='-';
        dfs(i+1);
        return 0;
    }

    if (i== s.size()){ // xét đến tín hiệu cuối
        if (kthuc==dem(a) ) //kt xem vị trí kthuc này đúng ko
            dung++;
    }

    return 0;
}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>s;
    cin>>k;

    kthuc=dem(s); //điểm kết thúc đúng
    dfs(0); // đi các trường hợp có thể

    //đếm số dấu chấm hỏi
    int chamhoi=0;
    for (int i=0;i<k.size();i++){
        if (k[i]=='?')
            chamhoi++;
    }
    // số trường hợp có thể đi
    int truonghop=pow(2,chamhoi);

    //in kq
    // % = số lần đúng / tổng số TH
    double kq = dung*1.0/ truonghop; // nhân 1.0 để đổi sang double
    cout << fixed<< setprecision(12) << kq << endl; // phải có fixed
    return 0;
}
