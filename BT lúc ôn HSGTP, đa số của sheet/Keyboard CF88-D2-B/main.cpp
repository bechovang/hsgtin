// truc toa do


#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k; cin>>n>>m>>k;

    char s[n][m];
    map <char,int> hm; // map để lưu đánh dấu khả năng ghi thường/ hoa
    vector <pair<int,int>> shift; // lưu vị trí của shift
    // nhập bàn phím vô mảng + lưu vị trí của shift
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>s[i][j];
            if (s[i][j]!='S')
                hm[s[i][j]]=1;
            else
                shift.push_back({i,j});
        }
    }

    // kt khả năng ghi thường/ hoa của các chữ trên bàn phím
    for (int o=0;o<shift.size();o++){ //shift
        for (int i=0;i<n;i++){          // s
            for (int j=0;j<m;j++){      // s
                if (s[i][j]!='S'){
                    int kcdoc= abs(i-shift[o].first);
                    int kcngang=abs(j-shift[o].second);
                    double kc= sqrt( pow(kcdoc,2)  +  pow(kcngang,2) ); // tính kc giữa shift và chữ đang xét
                    if (kc<=k)
                        hm[s[i][j]]=2;
                }

            }
        }
    }
    // trong hm, với 1 tay:
    //1 là chỉ ghi được chứ thường
    //2 là có thể ghi hoa và thường
    //còn lại là shift (=0)


    // gõ văn bản đề cho xem gõ được không?
    // nếu gõ được cần bao nhiêu lần gõ 2 tay
    int ng; cin>>ng;
    char g[500001]; cin>>g; // văn bàn cần gõ, giới hạn 5,10^5

    int dem=0;
    for (int i=0;i<ng;i++){
        if (g[i]==toupper(g[i])){// chữ đang xét là chữ hoa
            if (shift.empty()==true){ // bàn phím không có shift
                cout<<-1;
                return 0;
            }
            if (hm[tolower(g[i])]==2) // kt chữ này ghi hoa với 1 tay đc ko?
                dem++;
        }
        else{
            if (hm[tolower(g[i])]>=1) // kt chữ này ghi thường với 1 tay đc ko?
                dem++;
        }
        if (hm[tolower(g[i])]!=2 and hm[tolower(g[i])]!=1){ // bàn phím không có chữ này
            cout<<-1;
            return 0;
        }

    }
    cout<<ng-dem<<endl; // kq = số lượng chữ của văn bản - số chữ gõ được 1 tay = số chữ phải gõ 2 tay


    return 0;
}
