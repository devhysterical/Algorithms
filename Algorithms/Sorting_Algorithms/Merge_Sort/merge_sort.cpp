/*
- Merge Sort (sắp xếp trộn) sắp xếp dãy số bằng cách chia dãy thành 2 phần bằng nhau, sắp xếp từng phần rồi trộn 2 phần đã sắp xếp lại với nhau.
- Độ phức tạp: O(nlogn)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm merge thực hiện quá trình gộp hai mảng con đã sắp xếp thành một mảng hoàn chỉnh.
void merge(vector<int> &arr, int l, int m, int r)
{
  // Tính số phần tử của hai mảng con.
  int n1 = m - l + 1;
  int n2 = r - m;
  // Tạo mảng tạm L[] và R[].
  vector<int> L(n1);
  vector<int> R(n2);
  // Sao chép dữ liệu vào mảng tạm L[] và R[].
  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[m + 1 + j];
  }
  // Gộp hai mảng con đã sắp xếp vào arr.
  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  // Sao chép các phần tử còn lại của mảng L vào arr nếu có.
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  // Sao chép các phần tử còn lại của mảng R vào arr nếu có.
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Hàm merge_sort thực hiện quá trình chia đôi mảng và gọi đệ quy hàm merge_sort cho hai mảng con.
void merge_sort(vector<int> &arr, int l, int r)
{
  // Nếu chỉ có một phần tử hoặc không có phần tử nào thì dừng đệ quy.
  if (l >= r)
  {
    return;
  }
  // Tìm chỉ số phần tử ở giữa.
  int m = l + (r - l) / 2;
  // Gọi đệ quy merge_sort cho hai mảng con.
  merge_sort(arr, l, m);
  merge_sort(arr, m + 1, r);
  // Gộp hai mảng con đã sắp xếp.
  merge(arr, l, m, r);
}

int main()
{
  vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
  merge_sort(arr, 0, arr.size() - 1);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}