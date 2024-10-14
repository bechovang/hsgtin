/**
 * Chuong trinh tim uoc chung lon nhat (USCLN)
 * va boi so chung nho nhat (BSCNN) cua 2 so a và b
 *
 * @author viettuts.vn
 */

#include <iostream>

using namespace std;


int main() {
 int n,o,kq;
    int a[1000001];

    kq=0;
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }

    for (int i=1;i<=n;i++){
        if (i%2==0){
            kq=kq+a[i];
        }
    }
	cout << kq ;
}
