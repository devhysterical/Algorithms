#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<int> in_degree;

void topological_sort(int n)
{
  queue<int> q;

  // Thêm đỉnh có thứ bậc bằng 0 vào hàng đợi
  for (int i = 1; i <= n; ++i)
  {
    if (in_degree[i] == 0)
    {
      q.push(i);
    }
  }

  while (!q.empty())
  {
    int current_vertex = q.front();
    q.pop();

    // In đỉnh hiện tại
    cout << current_vertex << " ";

    // Lặp qua tất cả các đỉnh kề
    for (int neighbor : adj_list[current_vertex])
    {
      // Giảm thứ bậc của đỉnh kề đi 1
      --in_degree[neighbor];

      // Nếu thứ bậc của đỉnh kề trở thành 0, đưa nó vào hàng đợi
      if (in_degree[neighbor] == 0)
      {
        q.push(neighbor);
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  // Khởi tạo đồ thị và mảng thứ bậc
  adj_list.resize(n + 1);
  in_degree.resize(n + 1, 0);

  // Nhập thông tin về các cạnh
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    ++in_degree[v];
  }

  cout << "Topological Sorting: ";
  topological_sort(n);

  return 0;
}
/*
6 6
1 2
1 3
2 4
2 5
3 5
4 6
Topological Sorting: 1 2 3 4 5 6
*/