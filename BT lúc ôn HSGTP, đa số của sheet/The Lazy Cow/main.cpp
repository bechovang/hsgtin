#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
     freopen("lazy.in", "r", stdin);
     freopen("lazy.out", "w", stdout);
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    int new_n = n * 2 + 1;
    vector<vector<int>> a(new_n, vector<int>(new_n));

    // đọc đầu vào và lưu mảng đã quay 45 độ
    // tra gg: How to rotate a matrix by 45 degrees?
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i + j][n - i + j - 1];
        }
    }

    // tao mang prefix
    // Tạo prefix từ 1 , <= new_n để ko bị out mảng
    vector<vector<int>> prefix(new_n + 1, vector<int>(new_n + 1));
    for (int i = 1; i <= new_n; i++) {
        for (int j = 1; j <= new_n; j++) {
            if (i > 0 && j > 0)
                prefix[i][j] = (a[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]);
        }
    }

    // tìm ô ăn được nhiều cỏ nhất
    // K ko nhân 2 vì các ô chéo cách nhau 2 ô là điều hiển nhiên
    int maxx = INT_MIN;
    vector<vector<int>> tg(new_n + 1, vector<int>(new_n + 1));
    for (int i = k; i <= new_n - k; i++) {
        for (int j = k; j <= new_n - k; j++) {
            int x1 = max(1, i - k);
            int y1 = max(1, j - k);
            int x2 = min(new_n, i + k);
            int y2 = min(new_n, j + k);
            tg[i][j] = (prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]);
            maxx = max(maxx, tg[i][j]);
        }
    }
    if (k >= n) {
		// the loop above did not run, and Bessie can reach everything
		// *TH đặc biệt
		maxx = prefix[new_n][new_n];
	}
    cout << maxx;

    return 0;
}
