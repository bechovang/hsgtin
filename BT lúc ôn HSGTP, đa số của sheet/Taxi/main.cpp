#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a>c) {
        cout<<a;
        return 0;
    }

    while (1){
        //khách trả giá trước
        if (a+b<c){ //nếu giá khánh định trả thấp hơn giá tài xế bây giờ
            a=a+b; // nó sẽ trả giá
        }
        else{
            cout<<c; // ko thì nó đồng ý lun
            break;
        }


        if (c-d>=a){ //nếu giá tài xế định trả ko bé hơn giá khánh bây giờ
            c=c-d; //thì nó trả giá
        }
        else{
            cout<<a; // ko thì nó đồng ý lun
            break;
        }



    }

    return 0;
}
