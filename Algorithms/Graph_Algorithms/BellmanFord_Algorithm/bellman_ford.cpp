#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
- Định nghĩa một cạnh trong đồ thị có trọng số, bao gồm đỉnh nguồn (src), đỉnh đích (dest) và trọng số (weight)
*/
struct Edge
{
  int src, dest, weight;
};

// Hàm Bellman-Ford để tìm đường đi ngắn nhất từ một đỉnh nguồn đến tất cả các đỉnh còn lại
void bellman_ford(const vector<Edge> &edges, int num_vertices, int source)
{
  // Khởi tạo mảng lưu trữ khoảng cách tạm thời từ đỉnh nguồn đến tất cả các đỉnh
  vector<int> distance(num_vertices, numeric_limits<int>::max());

  // Khoảng cách từ chính nó đến chính nó là 0
  distance[source] = 0;

  // Lặp qua tất cả các đỉnh
  for (int i = 0; i < num_vertices - 1; ++i)
  {
    // Lặp qua tất cả các cạnh
    for (const Edge &edge : edges)
    {
      // Nếu có thể cải thiện khoảng cách từ đỉnh nguồn đến đỉnh đích thông qua cạnh
      if (distance[edge.src] != numeric_limits<int>::max() &&
          distance[edge.src] + edge.weight < distance[edge.dest])
      {
        distance[edge.dest] = distance[edge.src] + edge.weight;
      }
    }
  }
  // Kiểm tra xem có chu trình âm hay không
  for (const Edge &edge : edges)
  {
    if (distance[edge.src] != numeric_limits<int>::max() &&
        distance[edge.src] + edge.weight < distance[edge.dest])
    {
      cout << "Do thi chua chu trinh am." << endl;
      return;
    }
  }
  // In đường đi ngắn nhất từ đỉnh nguồn đến tất cả các đỉnh
  cout << "Khoang cach tu dinh nguon " << source << " den cac dinh khac la:" << endl;
  for (int i = 0; i < num_vertices; ++i)
  {
    cout << "Tu " << source << " den " << i << ": " << distance[i] << endl;
  }
}

int main()
{
  // Khởi tạo đồ thị có trọng số
  vector<Edge> edges = {
      {0, 1, 4},
      {0, 2, 5},
      {1, 2, -2},
      {1, 3, 6},
      {2, 3, 1}};

  int num_vertices = 4; // Số lượng đỉnh trong đồ thị
  int source = 0;       // Đỉnh nguồn

  // Gọi hàm bellman_ford để tìm đường đi ngắn nhất
  bellman_ford(edges, num_vertices, source);

  return 0;
}