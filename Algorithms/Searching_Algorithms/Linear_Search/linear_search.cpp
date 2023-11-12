#include <iostream>
#include <vector>

using namespace std;

// Hàm linear_search thực hiện tìm kiếm tuyến tính trong một mảng
int linear_search(const vector<int> &arr, int target)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == target)
    {
      return i; // Phần tử được tìm thấy, trả về chỉ số của nó
    }
  }
  return -1; // Nếu không tìm thấy, trả về -1
}

int main()
{
  // Khởi tạo mảng
  vector<int> arr = {4, 2, 7, 1, 8, 3, 5, 4};
  int target = 8; // Phần tử cần tìm
  // Gọi hàm linear_search để tìm kiếm phần tử trong mảng
  int result = linear_search(arr, target);
  // In kết quả
  if (result != -1)
  {
    cout << "Phan tu " << target << " duoc tim thay tai vi tri " << result << endl;
  }
  else
  {
    cout << "Phan tu " << target << " khong duoc tim thay trong mang" << endl;
  }
  return 0;
}
