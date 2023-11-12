/*
- Radix Sort (sắp xếp cơ số) là một thuật toán sắp xếp không so sánh được thiết kế để sắp xếp các số nguyên dựa trên các chữ số của chúng. Nó sắp xếp từ chữ số thấp nhất đến chữ số cao nhất hoặc ngược lại.
- Độ phức tạp: O(n * k) với n là số phần tử của dãy số và k là số chữ số của giá trị lớn nhất trong dãy số.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
- Hàm tính toán chữ số trong một số nguyên bằng cách lặp qua và chia liên tục cho 10 cho đến khi số đó bằng 0.
*/
int count_digits(int num)
{
  int count = 0;
  while (num > 0)
  {
    num /= 10;
    count++;
  }
  return count;
}

// Hàm radix_sort để sắp xếp mảng dựa trên các chữ số
void radix_sort(vector<int> &arr)
{
  // Tìm số lớn nhất để biết số chữ số cần sắp xếp
  int max_element = *max_element(arr.begin(), arr.end());
  int digits = count_digits(max_element);

  // Lặp qua từng chữ số (từ chữ số thấp nhất đến chữ số cao nhất)
  for (int exp = 1; max_element / exp > 0; exp *= 10)
  {
    // Sắp xếp mảng dựa trên chữ số thứ exp
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    // Đếm số lần xuất hiện của mỗi chữ số
    for (int i = 0; i < arr.size(); i++)
    {
      count[(arr[i] / exp) % 10]++;
    }

    // Cập nhật mảng count để chứa vị trí cuối cùng của mỗi chữ số
    for (int i = 1; i < 10; i++)
    {
      count[i] += count[i - 1];
    }

    // Xây dựng mảng output
    for (int i = arr.size() - 1; i >= 0; i--)
    {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }

    // Sao chép mảng output vào mảng ban đầu
    arr = output;
  }
}

int main()
{
  // Khởi tạo mảng
  vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

  // Gọi hàm radix_sort để sắp xếp mảng
  radix_sort(arr);

  // In mảng đã sắp xếp
  cout << "Mang da sap xep: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
