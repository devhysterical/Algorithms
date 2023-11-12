#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Giá trị vô cùng lớn đại diện cho vô cùng xa

// Hàm Floyd-Warshall để tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh
void floyd_warshall(vector<vector<int>> &graph)
{
  int num_vertices = graph.size();

  // Lặp qua tất cả các đỉnh làm đỉnh trung gian
  for (int k = 0; k < num_vertices; ++k)
  {
    // Lặp qua tất cả các cặp đỉnh (i, j) để cập nhật đường đi ngắn nhất
    for (int i = 0; i < num_vertices; ++i)
    {
      for (int j = 0; j < num_vertices; ++j)
      {
        // Nếu đỉnh k là một đỉnh trung gian và cạnh từ i đến j thông qua k ngắn hơn đường hiện tại
        if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j])
        {
          // Cập nhật đường đi ngắn nhất từ i đến j
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}

int main()
{
  // Khởi tạo đồ thị có trọng số (ma trận trọng số)
  vector<vector<int>> graph = {
      {0, 3, INF, 7},   // Đỉnh 0 kề với đỉnh 1 (trọng số 3) và đỉnh 3 (trọng số 7)
      {INF, 0, 2, INF}, // Đỉnh 1 không có cạnh trực tiếp đến các đỉnh khác
      {INF, INF, 0, 1}, // Đỉnh 2 không có cạnh trực tiếp đến các đỉnh khác
      {6, INF, INF, 0}  // Đỉnh 3 kề với đỉnh 0 (trọng số 6)
  };
  // Gọi hàm floyd_warshall để tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh
  floyd_warshall(graph);

  // In ma trận trọng số sau khi tìm đường đi ngắn nhất
  cout << "Ma tran trong so sau khi tim duong di ngan nhat:" << endl;
  for (int i = 0; i < graph.size(); ++i)
  {
    for (int j = 0; j < graph[i].size(); ++j)
    {
      if (graph[i][j] == INF)
      {
        cout << "INF ";
      }
      else
      {
        cout << graph[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
