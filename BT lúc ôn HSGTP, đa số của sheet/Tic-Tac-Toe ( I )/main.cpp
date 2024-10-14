#include <bits/stdc++.h>

using namespace std;
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool is_win(string s){
    bool rows=false;
    //  s[0] != '.' and s[0]==s[1] and s[0]==s[2]
    //  VT này khác | VT 1,2,3 giống nhau
    //  O hoặc X    |

    if (s[0] != '.' and s[0]==s[1] and s[0]==s[2] or
        s[3] != '.' and s[3]==s[4] and s[3]==s[5] or
        s[6] != '.' and s[6]==s[7] and s[6]==s[8]){
            rows=true;
        }
    bool columns=false;
    if (s[0] != '.' and s[0]==s[3] and s[0]==s[6] or
        s[1] != '.' and s[1]==s[4] and s[1]==s[7] or
        s[2] != '.' and s[2]==s[5] and s[2]==s[8]){
            columns=true;
        }
    bool diagonals=false;
    if (s[0] != '.' and s[0]==s[4] and s[0]==s[8] or
        s[2] != '.' and s[2]==s[4] and s[2]==s[6] ){
            diagonals=true;
        }
    if (rows==true or columns==true or diagonals==true)
        return true;
    else
        return false;
}

char doiluot(char k){
    if (k=='O')
        return 'X';
    if (k=='X')
        return 'O';
}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        // nhập bàn cờ caro theo chuỗi string 9 kí tự
        string board;
        for (int i=0;i<3;i++){
            string x; cin>>x;
            board= board + x;
        }

        // BFS
        queue <pair<string,char>>q; // pair: bàn cờ và lượt đánh
        q.push({".........",'X'}); // add bàn cờ trống trơn và lượt đánh này là của người X

        string kq="no";

        while(q.empty()!=true){ // chạy đến khi nào q trống
            string banco=q.front().first;  //lấy first của phần tử ngoài cùng của queue
            char luot=q.front().second;  //lấy seccond của phần tử ngoài cùng của queue
            q.pop(); // bỏ phần tử vừa lấy đi
            if (banco==board){ // bàn cờ hiện tại là input
                kq="yes";  // => yes và thoát
                break;
            }
            if (is_win(banco)==true) continue; // nếu mà bàn cờ hiện tại có người thắng rồi thì bỏ qua, ko BFS nữa
            for (int i=0;i<9;i++){
                if (banco[i]=='.' and luot==board[i]){ // duyệt qua các ô có thể đánh được <=> ô cờ hiện tại trống và ô này trong input == luot
                    banco[i]=luot;  // đánh X/O vào ô trống
                    q.push({banco, doiluot(luot)}); // cập nhật bàn cờ có ô vừa đánh và đổi lượt O/X

//                    //debug
//                    cout<<banco<<endl;

                    banco[i]='.'; // lùi lại nước vừa đánh <=> quay lui
                }
            }

        }

        cout<<kq<<endl;
    }

    return 0;
}
