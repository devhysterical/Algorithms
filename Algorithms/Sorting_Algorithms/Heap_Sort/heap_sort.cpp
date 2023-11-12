/*
- Heap Sort (sắp xếp vun đống) sắp xếp dãy số bằng cách xây dựng một heap từ dãy số và lấy ra từng phần tử lớn nhất từ heap.
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

// Hàm heapify để xây dựng một heap từ một mảng
void heapify(vector<int> &arr, int n, int i)
{
  int largest = i;       // Khởi tạo largest là root
  int left = 2 * i + 1;  // Chỉ số của nút con trái
  int right = 2 * i + 2; // Chỉ số của nút con phải

  // So sánh nút root với nút con trái và nút con phải (nếu có)
  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }
  // Nếu largest không phải là root, hoán đổi và heapify lại nút bị ảnh hưởng
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

// Hàm heap_sort để sắp xếp mảng sử dụng heap
void heap_sort(vector<int> &arr)
{
  int n = arr.size();
  // Xây dựng heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  // Sắp xếp mảng bằng cách lấy ra từng phần tử lớn nhất từ heap
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]); // Di chuyển root (phần tử lớn nhất) đến cuối mảng
    heapify(arr, i, 0);   // Gọi heapify để giảm heap size
  }
}

int main()
{
  // Khởi tạo mảng
  vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
  // Kích thước của mảng
  int n = arr.size();
  // Gọi hàm heap_sort để sắp xếp mảng
  heap_sort(arr);
  // In mảng đã sắp xếp
  cout << "Mang da sap xep: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
