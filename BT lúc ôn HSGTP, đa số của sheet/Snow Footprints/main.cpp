#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // nhập đề
    int n; cin>>n;
    char s[1001]; cin>>s;


//    Theo yêu cầu đề:
//    Chỉ có 3 TH có thể xảy ra:
//    RRRR
//    LLLL
//    RRLL
//
//    LLRR và RLRL là vô lí

    int batdau=0;
    int ketthuc=0;
    // tìm vị trí chữ cái đầu tiên <=> vt bắt đầu
    for (int i=0;i<n;i++){
        if (s[i]!='.'){
            batdau=i;
            break;
        }
    }

    // tìm vt kết thúc
    if (s[batdau]=='R'){ // nếu chữ đàu = R
        for (int i=n;i>=batdau+1;i--){ // đi từ phải qua trái
            if (s[i]=='L'){ // tìm chữ L gần trái nhất
                ketthuc=i-1;
            }
            if (s[i]=='.'){// hoặc tìm dấu '.' gần trái nhất
                ketthuc=i;
            }
        }
    }

    if (s[batdau]=='L'){// nếu chữ đầu = L
        ketthuc=batdau-1; // vt kết thúc là batdau-1
    }// vì chữ đầu = L => TH: .LLLLL. nên nếu vt bắt đầu là chữ L
    // thì nó sẽ đi qua phải 1 mạch rồi vòng về batdau-1
    // để được 1 đoạn full L
    //VD: .LLLLL. sẽ đi như sau:
    //    RRRRR' '
    //    ' 'LLLLL

    cout<<batdau+1<<' '<<ketthuc+1;
    return 0;
}
