#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Giá trị vô cùng lớn đại diện cho vô cùng xa

// Hàm Dijkstra's để tìm đường đi ngắn nhất
void dijkstra(const vector<vector<pair<int, int>>> &graph, int start)
{
  int num_vertices = graph.size();

  // Mảng để lưu trữ khoảng cách tạm thời từ đỉnh nguồn đến tất cả các đỉnh
  vector<int> distance(num_vertices, INF);

  // Set để lưu trữ các đỉnh và khoảng cách tạm thời từ đỉnh nguồn đến chúng
  set<pair<int, int>> s;

  // Đặt khoảng cách từ chính nó đến chính nó là 0
  distance[start] = 0;

  // Thêm đỉnh nguồn vào set với khoảng cách tạm thời
  s.insert({0, start});

  while (!s.empty())
  {
    // Lấy đỉnh có khoảng cách tạm thời nhỏ nhất từ set
    int current_vertex = s.begin()->second;
    s.erase(s.begin());

    // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
    for (const auto &neighbor : graph[current_vertex])
    {
      int adjacent_vertex = neighbor.first;
      int weight = neighbor.second;
      // Nếu có thể cải thiện khoảng cách từ đỉnh nguồn đến đỉnh kề
      if (distance[current_vertex] != INF &&
          distance[current_vertex] + weight < distance[adjacent_vertex])
      {
        // Cập nhật khoảng cách tạm thời và thêm vào set
        s.erase({distance[adjacent_vertex], adjacent_vertex});
        distance[adjacent_vertex] = distance[current_vertex] + weight;
        s.insert({distance[adjacent_vertex], adjacent_vertex});
      }
    }
  }
  // In khoảng cách từ đỉnh nguồn đến tất cả các đỉnh
  cout << "Khoang cach tu dinh nguon " << start << " den cac dinh khac la:" << endl;
  for (int i = 0; i < num_vertices; ++i)
  {
    cout << "Tu " << start << " den " << i << ": ";
    if (distance[i] == INF)
    {
      cout << "Khong co duong di." << endl;
    }
    else
    {
      cout << distance[i] << endl;
    }
  }
}

int main()
{
  // Khởi tạo đồ thị có trọng số
  vector<vector<pair<int, int>>> graph = {
      {{1, 4}, {2, 5}},         // Đỉnh 0 kề với đỉnh 1 (trọng số 4) và đỉnh 2 (trọng số 5)
      {{0, 4}, {2, 2}, {3, 6}}, // Đỉnh 1 kề với đỉnh 0 (trọng số 4), đỉnh 2 (trọng số 2), và đỉnh 3 (trọng số 6)
      {{0, 5}, {1, 2}, {3, 1}}, // Đỉnh 2 kề với đỉnh 0 (trọng số 5), đỉnh 1 (trọng số 2), và đỉnh 3 (trọng số 1)
      {{1, 6}, {2, 1}}          // Đỉnh 3 kề với đỉnh 1 (trọng số 6) và đỉnh 2 (trọng số 1)
  };
  int start_vertex = 0; // Đỉnh nguồn

  // Gọi hàm dijkstra để tìm đường đi ngắn nhất
  dijkstra(graph, start_vertex);

  return 0;
}
