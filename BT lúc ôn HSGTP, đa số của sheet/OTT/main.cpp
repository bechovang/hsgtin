#include <iostream>

using namespace std;
void file(){
    freopen("OTT.inp","r",stdin);
    freopen("OTT.out","w",stdout);
}
int main()
{
    //file();
    string a,b;
    cin >>a>>b;

    if (a=="S" and b=="S"){
        cout << "D";
    }
    if (a=="S" and b=="R"){
        cout << "B";
    }
    if (a=="S" and b=="P"){
        cout << "A";
    }
    if (a=="R" and b=="S"){
        cout << "A";
    }
    if (a=="R" and b=="R"){
        cout << "D";
    }
    if (a=="R" and b=="P"){
        cout << "B";
    }
    if (a=="P" and b=="S"){
        cout << "B";
    }
    if (a=="P" and b=="R"){
        cout << "A";
    }
    if (a=="P" and b=="P"){
        cout << "D";
    }


    return 0;
}
