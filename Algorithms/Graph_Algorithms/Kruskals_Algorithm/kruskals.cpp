#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa một cạnh trong đồ thị có trọng số
struct Edge
{
  int src, dest, weight;

  // Hàm so sánh cạnh dựa trên trọng số
  bool operator<(const Edge &other) const
  {
    return weight < other.weight;
  }
};

// Hàm tìm tập hợp của một đỉnh
int findSet(int i, const vector<int> &parent)
{
  // Nếu đỉnh là cha của chính nó, trả về đỉnh
  if (parent[i] == -1)
  {
    return i;
  }
  // Ngược lại, tìm tập hợp của cha của đỉnh
  return findSet(parent[i], parent);
}

// Hàm hợp nhất hai tập hợp chứa x và y
void unionSets(int x, int y, vector<int> &parent)
{
  // Tìm tập hợp của x và y
  int xSet = findSet(x, parent);
  int ySet = findSet(y, parent);

  // Gán cha của tập hợp của y là x
  parent[ySet] = xSet;
}

// Hàm Kruskal để tìm cây khung ngắn nhất
void kruskal(const vector<Edge> &edges, int numVertices)
{
  // Sắp xếp các cạnh theo trọng số tăng dần
  vector<Edge> sortedEdges = edges;
  sort(sortedEdges.begin(), sortedEdges.end());

  // Tạo mảng parent để lưu tập hợp của mỗi đỉnh
  vector<int> parent(numVertices, -1);

  cout << "Cay khung ngan nhat: " << endl;

  // Duyệt qua các cạnh theo thứ tự tăng dần của trọng số
  for (const Edge &edge : sortedEdges)
  {
    int srcSet = findSet(edge.src, parent);
    int destSet = findSet(edge.dest, parent);

    // Nếu hai đỉnh không thuộc cùng một tập hợp, thêm cạnh vào cây khung và hợp nhất hai tập hợp
    if (srcSet != destSet)
    {
      cout << edge.src << " - " << edge.dest << " (trong so " << edge.weight << ")" << endl;
      unionSets(srcSet, destSet, parent);
    }
  }
}

int main()
{
  // Khởi tạo đồ thị có trọng số
  vector<Edge> edges = {
      {0, 1, 4},
      {0, 7, 8},
      {1, 2, 8},
      {1, 7, 11},
      {2, 3, 7},
      {2, 8, 2},
      {2, 5, 4},
      {3, 4, 9},
      {3, 5, 14},
      {4, 5, 10},
      {5, 6, 2},
      {6, 7, 1},
      {6, 8, 6},
      {7, 8, 7}};

  int numVertices = 9; // Số lượng đỉnh trong đồ thị

  // Gọi hàm kruskal để tìm cây khung ngắn nhất
  kruskal(edges, numVertices);

  return 0;
}