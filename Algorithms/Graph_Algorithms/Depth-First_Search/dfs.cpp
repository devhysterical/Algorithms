#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Hàm DFS để duyệt đồ thị theo chiều sâu
void dfs(const vector<vector<int>> &graph, int start)
{
  int num_vertices = graph.size(); // Số đỉnh của đồ thị

  // Mảng để theo dõi các đỉnh đã được duyệt
  vector<bool> visited(num_vertices, false);

  // Stack để lưu trữ các đỉnh đang xem xét
  stack<int> s;

  // Bắt đầu từ đỉnh nguồn và đánh dấu nó đã được duyệt
  visited[start] = true;
  s.push(start);

  cout << "Thu tu duyet DFS: ";

  while (!s.empty())
  {
    // Lấy đỉnh từ đỉnh đầu stack
    int current_vertex = s.top();
    s.pop();

    // In đỉnh hiện tại
    cout << current_vertex << " ";

    // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
    for (int neighbor : graph[current_vertex])
    {
      // Nếu đỉnh kề chưa được duyệt, đánh dấu và thêm vào stack
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        s.push(neighbor);
      }
    }
  }
  cout << endl;
}

int main()
{
  // Khởi tạo đồ thị không có trọng số
  vector<vector<int>> graph = {
      {1, 2},    // Đỉnh 0 kề với đỉnh 1 và 2
      {0, 2, 3}, // Đỉnh 1 kề với đỉnh 0, 2, 3
      {0, 1, 3}, // Đỉnh 2 kề với đỉnh 0, 1, 3
      {1, 2}     // Đỉnh 3 kề với đỉnh 1, 2
  };
  int start_vertex = 0; // Đỉnh nguồn

  // Gọi hàm DFS để duyệt đồ thị
  dfs(graph, start_vertex);

  return 0;
}
