#include <bits/stdc++.h>

using namespace std;
#define endl'\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

char a[105];

// tìm 3 màu bên trái và 3 màu bên phải của a[i]
string funclienke(int i){
    string k="";
    for (int j=i-1;j>=i-3;j--){
        k=k+a[j];
    }
    for (int j=i+1;j<=i+3;j++){
        k=k+a[j];
    }
    return k;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //ROYGBIV
    int n; cin>>n;
    char color[]={'R','O','Y','G','B','I','V'};

    for (int i=0;i<=n+5;i++){
        a[i]='X';
    }
    //7 màu đầu cố định: để có đủ 7 màu
    a[1]='R';
    a[2]='O';
    a[3]='Y';
    a[4]='G';
    a[5]='B';
    a[6]='I';
    a[7]='V';
    // thêm n+4 màu để thành vòng tròn
    a[n+1]='R';
    a[n+2]='O';
    a[n+3]='Y';
    a[n+4]='G';
    // chọn màu cho a[8] đến a[n]:
    // + màu đó phải khác 3 màu bên trái và 3 màu bên
    // => thì mới có 4 màu liên tiếp khác nhau
    for (int i=8;i<=n;i++){
        string lienke=funclienke(i);
        for (int j=0;j<7;j++){ //color
            bool kt=true;
            for (int z=0;z<lienke.size();z++){ //lienke
                if (color[j]==lienke[z]){
                    kt=false;
                    break;
                }
            }
            if (kt==true){
                a[i]=color[j];
                break;
            }
        }
    }

    // in ra n màu ( từ ô 1 đến ô n)
    for (int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
