#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
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

bool done(string s){
    for (int i=0;i<9;i++){
        if (s[i]=='.')
            return false;
    }
    return true;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string board;
    while (board!="end"){
        cin>>board;
        if (board=="end") break;

        //BFS
        queue <pair<string,char>>q;
        q.push({".........",'X'});
        string kq="invalid";

        while (q.empty()!=true){
            string banco=q.front().first;
            char luot=q.front().second;
            q.pop();

            if (banco==board and is_win(banco)==true or
                banco==board and done(banco)==true){
                kq="valid";
            }
            else if (is_win(banco)==true){
                continue;  // qua TH kế
            }

            for (int i=0;i<9;i++){
                if (banco[i]=='.' and luot==board[i]){
                    banco[i]=luot;
                    q.push({banco,doiluot(luot)});
                    banco[i]='.';
                }
            }

        }

        if (board!="end")
            cout<<kq<<endl;

    }
    return 0;
}
