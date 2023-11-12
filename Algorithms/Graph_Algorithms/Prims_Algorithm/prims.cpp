#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define INF 1e9
typedef pair<int, int> ii;
vector<ii> a[MAX];
int n, m;
int d[MAX], p[MAX];
bool vis[MAX];

void prim(int s)
{
  // Khởi tạo mảng d với giá trị INF, đại diện cho trọng số tạm thời của các đỉnh
  for (int i = 1; i <= n; i++)
    d[i] = INF;
  d[s] = 0;                                      // Đặt trọng số của đỉnh bắt đầu là 0.
  priority_queue<ii, vector<ii>, greater<ii>> q; // Sử dụng hàng đợi ưu tiên để lựa chọn đỉnh có trọng số nhỏ nhất.
  q.push(ii(0, s));

  // Lặp cho đến khi hàng đợi ưu tiên trống.
  while (!q.empty())
  {
    int u = q.top().second; // Lấy ra đỉnh có trọng số nhỏ nhất.
    q.pop();

    // Nếu đỉnh đó đã được xét thì bỏ qua.
    if (vis[u])
      continue;
    vis[u] = true; // Đánh dấu đỉnh đó đã được xét.

    // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại.
    // Nếu đỉnh kề chưa được xét và có trọng số nhỏ hơn trọng số tạm thời, cập nhật lại trọng số tạm thời và thêm đỉnh đó vào hàng đợi ưu tiên.
    for (int i = 0; i < a[u].size(); i++)
    {
      int v = a[u][i].first;
      int w = a[u][i].second;
      if (!vis[v] && d[v] > w)
      {
        d[v] = w;
        p[v] = u;
        q.push(ii(d[v], v));
      }
    }
  }
}
int main()
{
  cin >> n >> m; // Nhập số đỉnh n và số cạnh m

  // Nhập thông tin về các cạnh và trọng số
  for (int i = 1; i <= m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    a[u].push_back(ii(v, w));
    a[v].push_back(ii(u, w));
  }
  // Gọi hàm prim với đỉnh bắt đầu là 1.
  prim(1);
  cout << "Cay khung nho nhat:" << endl;
  for (int i = 2; i <= n; i++)
  {
    cout << p[i] << " " << i << endl; // In ra các cạnh của cây khung nhỏ nhất.
  }
  return 0;
}