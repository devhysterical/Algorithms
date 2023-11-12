#include <iostream>
#include <vector>

using namespace std;

// Hàm binary_search thực hiện tìm kiếm nhị phân trong một mảng sắp xếp
int binary_search(const vector<int> &arr, int target)
{
  int left = 0;               // Chỉ số bắt đầu của mảng
  int right = arr.size() - 1; // Chỉ số kết thúc của mảng

  while (left <= right)
  {
    int mid = left + (right - left) / 2; // Chỉ số của phần tử giữa

    if (arr[mid] == target)
    {
      return mid; // Phần tử được tìm thấy, trả về chỉ số của nó
    }
    else if (arr[mid] < target)
    {
      left = mid + 1; // Nếu phần tử ở giữa nhỏ hơn target, loại bỏ nửa bên trái
    }
    else
    {
      right = mid - 1; // Nếu phần tử ở giữa lớn hơn target, loại bỏ nửa bên phải
    }
  }
  return -1; // Nếu không tìm thấy, trả về -1
}

int main()
{
  // Khởi tạo mảng đã sắp xếp
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 7; // Phần tử cần tìm
  // Gọi hàm binary_search để tìm kiếm phần tử trong mảng
  int result = binary_search(arr, target);
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