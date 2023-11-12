#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Hàm BFS để duyệt đồ thị theo chiều rộng
void bfs(const vector<vector<int>> &graph, int start)
{
  int num_vertices = graph.size();

  // Mảng để theo dõi các đỉnh đã được duyệt
  vector<bool> visited(num_vertices, false);

  // Queue để lưu trữ các đỉnh đang xem xét
  queue<int> q;

  // Bắt đầu từ đỉnh nguồn và đánh dấu nó đã được duyệt
  visited[start] = true;
  q.push(start);

  cout << "Thu tu duyet BFS: ";

  while (!q.empty())
  {
    // Lấy đỉnh từ đầu queue
    int current_vertex = q.front();
    q.pop();

    // In đỉnh hiện tại
    cout << current_vertex << " ";

    // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
    for (int neighbor : graph[current_vertex])
    {
      // Nếu đỉnh kề chưa được duyệt, đánh dấu và thêm vào queue
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        q.push(neighbor);
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

  // Gọi hàm BFS để duyệt đồ thị
  bfs(graph, start_vertex);

  return 0;
}
