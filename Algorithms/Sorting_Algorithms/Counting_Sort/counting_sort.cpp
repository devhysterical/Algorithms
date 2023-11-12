/*
- Counting Sort (sắp xếp đếm) sắp xếp dãy số bằng cách đếm số lần xuất hiện của từng phần tử trong dãy số.
- Độ phức tạp: O(n + k) với n là số phần tử của dãy số và k là giá trị lớn nhất trong dãy số.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
- Tìm giá trị lớn nhất trong mảng để xác định kích thước mảng đếm (count).
- Tạo mảng đếm (count) và khởi tạo giá trị cho mỗi phần tử là 0.
- Đếm số lần xuất hiện của mỗi phần tử và lưu vào mảng đếm (count).
- Cập nhật mảng đếm (count) để chứa vị trí cuối cùng của mỗi phần tử trong mảng sắp xếp.
- Tạo mảng kết quả và điền giá trị vào mảng này dựa trên mảng đếm (count).
- Sao chép mảng kết quả vào mảng ban đầu.
*/
void counting_sort(vector<int> &arr)
{
  // Tìm giá trị lớn nhất trong mảng để xác định kích thước mảng đếm
  int max_element = *max_element(arr.begin(), arr.end());

  // Tạo mảng đếm và khởi tạo giá trị cho mỗi phần tử là 0
  vector<int> count(max_element + 1, 0);

  // Đếm số lần xuất hiện của mỗi phần tử và lưu vào mảng đếm
  for (int i = 0; i < arr.size(); i++)
  {
    count[arr[i]]++;
  }

  // Cập nhật mảng đếm để chứa vị trí cuối cùng của mỗi phần tử trong mảng sắp xếp
  for (int i = 1; i <= max_element; i++)
  {
    count[i] += count[i - 1];
  }

  // Tạo mảng kết quả và điền giá trị vào mảng này dựa trên mảng đếm
  vector<int> result(arr.size());
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    result[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }
  // Sao chép mảng kết quả vào mảng ban đầu
  arr = result;
}

int main()
{
  // Khởi tạo mảng
  vector<int> arr = {4, 2, 7, 1, 8, 3, 5, 4};
  // Gọi hàm counting_sort để sắp xếp mảng
  counting_sort(arr);
  // In mảng đã sắp xếp
  cout << "Mang da sap xep: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
