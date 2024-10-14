#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    stack <ll> st;
    ll dem=0;
    for (int i=0;i<n;i++){
        int h; cin>>h>>h;
        if (st.empty()==true){ // chưa có thì thêm
            dem++;
            st.push(h);
            //debug
//            cout<<"push "<<h<<endl;
        }
        else {
            if (h > st.top()){ // cao hơn thì gắn
                dem++;
                st.push(h);
                //debug
//                cout<<"push "<<h<<endl;
            }
            if (h < st.top()){  // bé hơn thì cắt mấy cái cao hơn
                while (st.top()>h){
                    //debug
//                    cout<<"pop "<<st.top()<<endl;
                    st.pop();
                    if (st.empty()==true)
                        break;
                }
                if (st.empty()==true){  // cắt xong mấy cái cao hơn mà cái này chưa có thì gắn
                    dem++;
                    st.push(h);
                    //debug
        //            cout<<"push "<<h<<endl;
                }
                else if (h > st.top()){
                    dem++;
                    st.push(h);
                    //debug
//                    cout<<"push "<<h<<endl;
                }
            }
            if (h == st.top()){   // bằng thì đi tiếp
                continue;
            }
        }
    }

    cout<<dem;
    return 0;
}


//một số vấn đề có thể gây ra lỗi SIGSEGV:
//
//Trường hợp bạn thêm dữ liệu không hợp lệ vào stack,
//ví dụ: thêm vào stack khi nó rỗng hoặc pop khỏi stack khi nó đã rỗng.
//
//Không kiểm tra kích thước stack trước khi sử dụng st.top() hoặc st.pop().
//
//Không kiểm tra giá trị n và đảm bảo rằng bạn đọc đúng số lượng giá trị nếu cần.


//test lỗi runtime error (SIGSEGV)
//5
//5 2
//3 4
//1 7
//6 9
//8 0
