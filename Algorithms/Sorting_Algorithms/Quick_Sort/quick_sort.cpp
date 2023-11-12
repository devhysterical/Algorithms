/*
- Quick Sort (sắp xếp nhanh) sắp xếp dãy số bằng cách chọn một phần tử làm pivot và chia dãy thành 2 phần, một phần có các phần tử nhỏ hơn pivot, một phần có các phần tử lớn hơn pivot. Sau đó đệ quy sắp xếp hai phần đó.
- Độ phức tạp: O(nlogn)
*/

#include <iostream>
#include <vector>

using namespace std;

// Hàm swap giúp hoán đổi giá trị của hai phần tử trong mảng
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Hàm partition sắp xếp các phần tử trong mảng sao cho các phần tử nhỏ hơn pivot đều ở bên trái, lớn hơn đều ở bên phải
int partition(vector<int> &arr, int low, int high)
{
  // Chọn pivot là phần tử ở giữa
  int pivot = arr[low + (high - low) / 2];
  // Lặp qua mảng và sắp xếp các phần tử
  while (true)
  {
    // Tìm phần tử lớn hơn pivot ở bên trái
    while (arr[low] < pivot)
    {
      low++;
    }
    // Tìm phần tử nhỏ hơn pivot ở bên phải
    while (arr[high] > pivot)
    {
      high--;
    }
    // Nếu low >= high, mảng đã được sắp xếp
    if (low >= high)
    {
      return high;
    }
    // Hoán đổi phần tử lớn và nhỏ để đưa về đúng vị trí
    swap(arr[low], arr[high]);
    // Di chuyển các con trỏ về phía trước
    low++;
    high--;
  }
}

// Hàm quick_sort sử dụng đệ quy để sắp xếp mảng
void quick_sort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    // Phân chia mảng thành hai phần và lấy chỉ số của pivot
    int pivotIndex = partition(arr, low, high);

    // Gọi đệ quy cho hai phần của mảng
    quick_sort(arr, low, pivotIndex);
    quick_sort(arr, pivotIndex + 1, high);
  }
}

int main()
{
  // Khởi tạo mảng
  vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
  // Kích thước của mảng
  int n = arr.size();
  // Gọi hàm quick_sort để sắp xếp mảng
  quick_sort(arr, 0, n - 1);
  // In mảng đã sắp xếp
  cout << "Mang da sap xep: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}