#include <bits/stdc++.h>

using namespace std;

/*
 *
 *
 ******************************************** Giấy phép *******************************************
 * 																								*
 * Tệp này là một phần của Dãy video giảng dạy về Thuật toán bằng tiếng Ả Rập					*
 *	Do Eng Mostafa Saad thực hiện, Trợ giảng tại Đại học Cairo								*
 * 																								*
 *	Có sẵn trên Kênh YouTube của tôi: http://www.youtube.com/user/nobody123497?feature=mhee		*
 * 																								*
 * Hãy tự do sử dụng bất cứ lúc nào, cho bất kỳ lý do gì, bằng bất kỳ cách nào, mà không có bất kỳ nghĩa vụ nào. *
 * 																								*
 * 																								*
 * Trong trường hợp phát hiện lỗi, vui lòng thông báo cho tôi qua email: mostafa.saad.fci@gmail.com		*
 * 																								*
 * Mostafa Saad Ibrahim © 2013																	*
 * 																								*
 ************************************************************************************************
 *
 *
 */

/*
Phiên bản 10: STL

Nội dung
Các hoạt động cơ bản trên Vector
Thuật toán trên Vector
Hàng đợi \ Hàng đôi \ Hàng đợi Ưu tiên \ Ngăn xếp
Cặp \ Tập hợp \ Ánh xạ
Chuỗi (String)
StringStream
Valarray (Mảng giá trị)

//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=standardTemplateLibrary
//http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=standardTemplateLibrary2
//www.cplusplus.com/reference

*/

#include <functional>
#include <utility>
#include <numeric>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<valarray>
using namespace std;






// in ra
const int MAX = 100;  // Giới hạn tối đa

int in[MAX];  // Mảng lưu trữ đầu vào

void printLine(string sub = "") {
    for (int i = 0; i < 50; ++i) {
        cout << "*";
    }
    cout << sub;
    for (int i = 0; i < 50; ++i) {
        cout << "*";
    }
    cout << "\n";
}

void printVec(vector<int> v2, string s = "") {
    cout << s;
    for (int i = 0; i < (int)v2.size(); ++i)
        cout << v2[i] << " ";
    cout << "\n";
}

template<class T>
void printValArray(valarray<T> v2, string s = "") {
    cout << s;
    for (int i = 0; i < (int)v2.size(); ++i)
        cout << v2[i] << " ";
    cout << "\n";
}





#define all(v)          ((v).begin()), ((v).end())
#define sz(v)           ((int)((v).size()))

typedef vector<int> vi;

// Học hỏi tiêu đề của các top coder khác




// Nếu hàm của bạn không phải là một toán tử "<" đúng, có thể sẽ xảy ra lỗi RTE trong các trường hợp thử nghiệm lớn.
// Nếu a < b, thì b < a = false
// a và b được coi là tương đương nếu (!(a<b) && !(b<a))

bool sortPairsCmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first * b.second < a.second * b.second;
}

bool isOdd(int n) { return n % 2 != 0; }





void vectorBasicTest()
{
	vi v(10);	 							// Khởi tạo 10 phần tử với giá trị 0
	vi v1(10, 7);							// Khởi tạo 10 phần tử với giá trị 7

	// Còn về việc tạo vector từ mảng
	const int do_dai = 6;
	int mang[do_dai] = {5, 2, 7, 2, 0, 2};
	vi v2(mang, mang+do_dai);

	printVec(v2, "v2: ");

	cout<<"Phần tử đầu: "<<v2.front()<<" phần tử cuối: "<<v2.back()<<"\n";

	swap(v2.front(), v2.back());	// phần tử cuối được tham chiếu bởi back()
	printVec(v2, "đổi chỗ: ");

	// Vector từ Vector
	vi v3(v1.begin(), v1.end());

	v.resize(15);	// thay đổi kích thước từ 10 thành 15 - nếu bạn biết kích thước trước, thì nên sử dụng
	// điều gì sẽ xảy ra nếu chúng ta sử dụng push back? sẽ có một phần tử thứ 16 được thêm vào

	// Còn về lặp qua vector, có thể giống như mảng hoặc sử dụng iterators
	for (int i = 0; i < (int)v2.size(); ++i)	// chú ý: v.size() trả về giá trị không âm. Trả về v.size()-1 có thể gây ra vấn đề. Ép kiểu về int
		cout<<v2[i]<<" ";
	cout<<"\n";

	// Cách khác:
	vi::iterator it = v2.begin();
	while(it != v2.end())
	{
		cout<<(*it)<<" ";		// * hoạt động tương tự như con trỏ.
		++it;					// Di chuyển đến phần tử tiếp theo
	}
	cout<<"\n";


	// Sắp xếp vector
	sort(v2.begin(), v2.end());		// điều gì sẽ xảy ra nếu sắp xếp tất cả các phần tử, ngoại trừ 2 phần tử đầu: sort(v2.begin()+2, v2.end());

	printVec(v2, "đã sắp xếp: ");

	// Sắp xếp giảm dần
	sort(v2.begin(), v2.end(), greater<int>());	// để greater đứng đầu
	sort(v2.rbegin(), v2.rend());

	printVec(v2, "đã sắp xếp đảo ngược: ");

	// Tạo vector 2D của giá trị boolean
	vector< vector<bool> > vbs(10, vector<bool>(20, true));	// tạo mảng 10 * 20 với tất cả giá trị là true

	// So sánh 2 vector
	if(v1 < v2)	// tương tự <=, == //vector nào có các phần tử nhỏ hơn
		cout<<"v1 nhỏ hơn v2\n";
	else
		cout<<"v2 nhỏ hơn v1\n";

	// Xóa phần tử thứ 2
	v2.erase(v2.begin()+1);				// O(n)
	printVec(v2, "xóa phần tử thứ 2: ");

	v2.insert(v2.begin()+3, 14);		// O(n)
	printVec(v2, "chèn 14 vào vị trí thứ 4: ");

	v2.push_back(20);
	printVec(v2, "thêm 20 vào cuối: ");	// O(1)


	// Kiểm tra nếu phần tử có trong mảng

	if (find(all(v2), 7) != v2.end())	// find là O(n)
		cout<<"7 có trong v2\n";

	if (find(all(v2), 9) == v2.end())
		cout<<"9 không có trong v2\n";

	// Xóa giá trị 7. Nếu không tìm thấy phần tử, bạn không thể gọi hàm. Vui lòng kiểm tra trước
	v2.erase( find(all(v2), 7) );
	printVec(v2, "sau khi xóa 7 bằng find: ");

	reverse( all(v2) );
	printVec(v2, "vector đảo ngược: ");

	random_shuffle(all(v2));		// xáo trộn ngẫu nhiên các phần tử trong mảng
	printVec(v2, "vector đã xáo trộn: ");

	v2.pop_back();	// xóa phần tử cuối trong O(1)
	printVec(v2, "đã xóa cuối: ");

	v2.clear();
	printVec(v2, "vector đã xóa sạch: ");
}








bool isEqual(int a, int b) { return abs(a-b) < 2; }	// xem xét

// Thực tế rất nhiều nơi ở đây, áp dụng cho bất kỳ thứ gì có bộ lặp(iterators) (ví dụ: chuỗi)
void vectorManipulation()
{
	const int lenght = 10;
	int array[lenght] = {4, 2, 3, 2, 9, 2, 17, 17, 17, 20};
	vi v2(array, array+lenght);
	vi v1(v2.begin()+2, v2.begin()+5);

	printVec(v2, "V2: ");

	// Khoảng cách giữa hai trình lặp(iterators) = Bằng việc trừ các trình lặp(iterators) của họ: Ví dụ: it2 - it1 (trong đó it2 lớn hơn)
	cout<<"khoảng cách: "<<distance(v2.begin(), v2.begin()+3)<<"\n";
	cout<<"khoảng cách: "<<distance(v2.begin()+4, v2.begin())<<"\n";

	vector<int>::iterator it;

	vector<int> v3 = v2;	// sao chép
	replace(all(v3), 2, 7);
	printVec(v3, "V3: ");

	replace_if(all(v3), isOdd, 15);
	printVec(v3, "V3: ");

	// tìm kiếm 3 phần tử liên tiếp có giá trị là 17
	it = search_n(all(v2), 3, 17);

	if(it != v2.end())
		cout<<"3 phần tử liên tiếp có giá trị 17 từ vị trí: "<<it-v2.begin()<<"\n";

	it = search(all(v2), all(v1));			// tìm kiếm vector con
	if(it != v2.end())
		cout<<"vector con từ vị trí: "<<it-v2.begin()<<"\n";

	// unique/binary_search/lower_bound/upper_bound phải được áp dụng trên mảng ĐÃ ĐƯỢC SẮP XẾP.
	sort( all(v2) );
	printVec(v2, "Đã sắp xếp ");

	bool ans = binary_search(all(v2), 17);	//v2 phải được sắp xếp trước - O(logn)
	cout<<"Tìm kiếm giá trị 17: "<<ans<<"\n";

	// Tìm phần tử đầu tiên lớn hơn hoặc bằng một giá trị cho trước
	it = lower_bound(all(v2), 17);

	if(it != v2.end())
		cout<<"Phần tử đầu tiên >= 17 "<<*it<<"\n";

	// Tìm phần tử đầu tiên lớn hơn một giá trị cho trước
	it = upper_bound(all(v2), 17);
	if(it != v2.end())
		cout<<"Phần tử đầu tiên > 17 "<<*it<<"\n";

	// trả về trình lặp đến phần tử cuối cùng của mảng đã sắp xếp và không trùng lặp.
	v2.resize(unique( all(v2) ) - v2.begin());
	printVec(v2, "Loại bỏ các phần tử trùng: ");

	// set_intersection/set_difference/set_union/set_symmetric_difference phải được áp dụng trên mảng ĐÃ ĐƯỢC SẮP XẾP.
	v1 = v2;
	v1.push_back(v1.back());
	v1.push_back(v1.back()+20);
	v1.push_back(v1.back()+7);
	printVec(v1, "V1: ");
	vector<int> v;

	set_intersection(all(v1), all(v2), back_inserter(v));
	printVec(v, "Giao: ");

	v.clear();
	set_difference(all(v1), all(v2), back_inserter(v));
	printVec(v, "Hiệu: ");	// điều gì xảy ra nếu v1 là tập con hợp hợp v2? v sẽ trống

	v.clear();
	set_union(all(v1), all(v2), back_inserter(v));
	printVec(v, "Hợp: ");

	/////////////////////////////////////////////////////////////////////////////////

	int mx = *max_element(v2.begin(), v2.end());
	int mn = *min_element(v2.begin(), v2.end());

	cout<<"Giá trị lớn nhất: "<<mx<<" giá trị nhỏ nhất "<<mn<<"\n";
	printVec(v1, "v1: ");
	printVec(v2, "v2: ");

	swap_ranges(v2.end()-2, v2.end(), v1.begin() );	// bạn có thể hoán đổi từ các vector khác nhau

	printVec(v2, "Hoán đổi dãy ");

	v2.clear();
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(4);
	printVec(v2, "v2 mới: ");

	int vecSum = accumulate(all(v2), 0); 						// tổng của mảng
	int vecMul = accumulate(all(v2), 1, multiplies<int>()); 	// tích của mảng

	int sumOfProducts1 = inner_product(all(v2), v2.begin(), 0);			 						// tích tích của các phần tử: V1[0] * V1[0] + V2[0]*v2[0]...
	int sumOfProducts2 = inner_product(all(v2), v2.begin(), 0, plus<int>(), multiplies<int>()); // tương tự như trên
	int productsOfSum = inner_product(all(v2), v2.begin(), 1, multiplies<int>(), plus<int>()); // tích tổng: 1 * (V1[0] + V1[0]) * (V2[0] + v2[0])
	// 0, 1, 0 là giá trị khởi tạo cho tích lũy

	cout<<"Tổng mảng: "<<vecSum<<" tích mảng: "<<vecMul<<" Tích tích của các phần tử: "<<sumOfProducts1<<" Sự tích của tổng:"<<productsOfSum<<"\n";

	v1.clear();
	partial_sum(all(v2), back_inserter(v1));
	printVec(v1, "Dãy tích lũy: ");

	v1.clear();
	partial_sum(all(v2), back_inserter(v1), minus<int>());
	printVec(v1, "Dãy hiệu: ");

	// viết vào một luồng
	ostringstream oss1;
	partial_sum ( all(v2), ostream_iterator<int>(oss1," "));
	cout<<"Dãy tích lũy dưới dạng chuỗi: "<<oss1.str()<<"\n";			// 27 68 149 tích lũy một phần

	adjacent_difference(all(v2), v1.begin());
	printVec(v1, "Hiệu chênh lệch ");

	adjacent_difference (all(v2), v1.begin() , plus <int>());
	printVec(v1, "Tổng chênh lệch ");

	it = adjacent_find(all(v2), isEqual);	// tìm hai phần tử kề nhau có GIÁ TRỊ BẰNG nhau dựa trên hàm equal
	if(it != v2.end())
		cout<<"Hai giá trị kề nhau là: "<<*it<<" "<<*(it+1)<<"\n";

	v2.insert(v2.begin(), 6);
	v2.insert(v2.begin()+3, 6);
	v2.push_back(6);

	printVec(v2, "V2: ");

	cout<<"Số lần xuất hiện của 6: "<<count(all(v2), 6)<<"\n";
	count_if (all(v2), isOdd);	// isOdd là một hàm được gọi cho mỗi phần tử trong v2

	v2.erase(	remove(all(v2), 6)	, v2.end());	// xóa hết số 6, và duy trì thứ tự
	printVec(v2, "Xóa các số 6: ");

	rotate(v2.begin(), v2.begin()+1, v2.end()); 	// xoay theo hướng <--
	printVec(v2);

	// Trong trường hợp liệt kê tất cả next_permutation, bạn phải SẮP XẾP dữ liệu đầu vào trước
	sort( all(v2) );
	do {
		printVec(v2, "Perm: ");
	} while(next_permutation(all(v2)));	// tạo hoán vị trên bất kỳ vị trí chỉ định nào với hàm so sánh
}



void QueueStackBasicTest()
{
	queue<int> q;
	q.push(20);
	q.push(10);
	q.push(30);

	cout << "Phần tử cuối cùng trong Hàng đợi: " << q.back() << "\n";
	cout << "Các phần tử trong Hàng đợi: ";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";

	deque<int> dq;		// hàng đợi kép
	dq.push_back(20);
	dq.push_front(10);

	// Sắp xếp các phần tử, lớn trước
	priority_queue<int> pq;
	// priority_queue<int, cmp> pq;	// truyền cmp để sắp xếp chúng
	pq.push(20);
	pq.push(10);
	pq.push(30);

	cout << "Các phần tử trong Hàng đợi Ưu tiên: ";
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n";


	stack<int> s;
	s.push(20);
	s.push(10);
	s.push(30);

	cout << "Các phần tử trong Ngăn xếp: ";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}




void SetAndPairAndMapBasicTest()
{
	// Cặp (Pair)
	pair<int, char> p1 = make_pair(10, 'z');
	pair<string, pair<int, char> > p2 = make_pair("mostafa", p1);

	cout << p2.first << "\n";
	cout << p2.second.first << "\n";
	cout << p2.second.second << "\n";

	// Quy tắc: bất kỳ thuật toán / cấu trúc dữ liệu nào cần so sánh dữ liệu, ví dụ: sắp xếp
	// sẽ sử dụng các kiểu dữ liệu cơ bản để so sánh (ví dụ: 3 < 5), hoặc bạn cung cấp một hàm so sánh

	vector< pair<int, int> > vp;
	vp.push_back(make_pair(1, 2));
	vp.push_back(make_pair(4, 4));
	sort(all(vp), sortPairsCmp);

	////////////////////////////////////////////

	set<string> strSet;
	strSet.insert("mostafa");
	strSet.insert("ali");

	if (strSet.count("mostafa"))
		cout << "Mostafa có trong Tập hợp\n";

	set<string>::iterator strIt = strSet.lower_bound("mostafa");
	strIt = strSet.find("mostafa");

	//replace(all(strSet), "mostafa", "hani");	// Trong map và set, không nên thử thay đổi trung gian (intermediate playing). Chúng dựa trên các keys.

	map<string, int> mp;
	mp["Mostafa"] = 10;
	mp["Saad"] = 20;

	// Bạn có thể iterators map và set bình thường giống như vector. Không bao giờ thay đổi các key trong khi iterators

	// Cách khác, chuyển đổi map thành vector của cặp: key, value
	vector< pair<string, int> > mptov(all(mp));

	for (int i = 0; i < (int)mptov.size(); ++i)
		cout << mptov[i].first << " " << mptov[i].second << "\n";

	// map và set có độ phức tạp logn
	// multiset và multimap giống nhau nhưng cho phép sự lặp lại của khóa(keys repetition)
}


/////////////////////////////////
int toInt(string str) {
	int num;
	istringstream iss(str);
	iss >> num;
	return num;
}

template <class T> string toStr(T par) {
	ostringstream oss;
	oss << par;
	return oss.str();
}

bool startsWith(string str, string pat) {
	return (int)str.find(pat) == 0;
}

bool endsWith(string str, string pat) {
	int pos = str.rfind(pat);
	return pos != -1 && pos + sz(pat) == sz(str);
}

void stringBasicTest() {

	string str2("initial2");
	string test = "hi abc abc abc abc";

	// in ra 1 đoạn của string
	cout << test.substr(3) << "\n";	// abc abc abc abc
	cout << test.substr(3, 5) << "\n";	// abc

	cout << "Mostafa ở: " << test.find("Mostafa") << "\n";
	cout << "Mostafa ở: " << (int)test.find("Mostafa") << "\n";

	cout << test.find("abc", 5) << "\n";	// bắt đầu tìm kiếm tại ký tự thứ 6

	// Các hàm tìm kiếm MỘT KÝ TỰ từ chuỗi đã cho
	cout << test.find_last_of("cab") << "\n";
	cout << test.find_first_of("aic") << "\n";
	cout << test.find_first_of("aic", 4) << "\n";
	cout << test.find_first_of("aic", 4, 6) << "\n";
	cout << test.find_first_not_of("aic") << "\n";

	test.replace(4, 3, "x");	// thay thế từ vị trí 4, 3 ký tự bằng "x"

	char array[4] = {'a', 'b', 'c', 'd'};
	string t = array;	// Chuyển đổi mảng ký tự thành chuỗi.
	const char* s = t.c_str();	// Chuyển đổi mảng ký tự thành chuỗi.

	test.erase(4);	// Xóa từ vị trí 4 đến cuối chuỗi.
	cout << "Chuỗi " << test << "\n";
	test.erase(4, 6);	// Xóa 6 ký tự bắt đầu từ vị trí 4

	/////////////////////////////////////////////////
	cout << toStr(32) << "\n";

	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(7);

	ostringstream oss;
	copy(all(v), ostream_iterator<int>(oss, ","));	// chuyển đổi vector thành chuỗi
	cout << oss.str() << "\n";

	istringstream iss("10 20 30");	// hữu ích trong việc phân tích lại các khối đầu vào
	int x;
	while (iss >> x)	// tương tự khi sử dụng cin
		cout << "Đọc X " << x << "\n";
}

void valarrayTest()	// Nếu bạn muốn thực hiện nhiều hoạt động cơ bản, nhưng trên một nhóm số
{
	int val[] = {1, -2, 3, -4, -5};

	valarray<int> v1(val, 5);	// KHÔNG PHẢI (val, val+5)

	valarray<int> v2 = abs(v1);

	cout << v2.sum() << "\n";

	valarray<int> v3 = 2 * (v1 + v2);
	printValArray(v3, "v3: ");


	valarray<bool> v4 = (v1 == v2);
	cout << v4.min() << " " << v4.max() << "\n";

	double arr[] = {0, 1, 2, 3};
	valarray<double> v5(arr, 4);

	valarray<double> v6 = 2.0 * (v5 + 3.0 * v5);	// 2.0 KHÔNG PHẢI 2 - sử dụng cùng loại dữ liệu, không pha trộn

	cout << pow(2.0, v5).sum() << "\n";	// 2^4 - 1
	cout << pow(v5, 2.0).sum() << "\n";
	cout << pow(2.5 * v5, v6).sum() << "\n";
	//cout << pow(v5, 2.5 * v6).sum() << "\n";	// lỗi biên dịch

	// các hoạt động thú vị khác: slice_array,
}




int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


//    vectorBasicTest();
//    vectorManipulation();
//    QueueStackBasicTest();
//    SetAndPairAndMapBasicTest();
//    stringBasicTest();
    valarrayTest();


//    cout << "Hello world!" << endl;
    return 0;
}
