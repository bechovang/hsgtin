#include <iostream>
#include <vector>

using namespace std;

const int N = 7; // Số lượng đỉnh của đồ thị
vector<int> adj[N]; // Danh sách kề

vector<int> start(N, -1); // Thời điểm bắt đầu duyệt đỉnh
vector<int> finish(N, -1); // Thời điểm kết thúc duyệt đỉnh
int timer = 0; // Biến đếm thời gian

void dfs_EdgeClassification(int node)
{
    start[node] = timer++;
    cout << "Visiting node: " << node << endl;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int child = adj[node][i];
        cout << "Processing edge: " << node << " --> " << child << endl;

        if (start[child] == -1) // Not visited before. Tree Edge
        {
            cout << "Tree Edge: " << node << " --> " << child << endl;
            dfs_EdgeClassification(child);
        }
        else
        {
            if (finish[child] == -1) // Ancestor waiting to finish. Cycle. Back Edge
            {
                cout << "Back Edge: " << node << " --> " << child << endl;
            }
            else if (start[node] < start[child]) // You are my descendant. Forward Edge
            {
                cout << "Forward Edge: " << node << " --> " << child << endl;
            }
            else // Cross Edge
            {
                cout << "Cross Edge: " << node << " --> " << child << endl;
            }
        }
    }

    finish[node] = timer++;
    cout << "Finishing node: " << node << endl;
}

int main()
{

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);

    dfs_EdgeClassification(0);

    return 0;
}
