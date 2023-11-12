/*
- Bubble Sort (sắp xếp nổi bọt) sắp xếp dãy số bằng cách so sánh từng cặp phần tử liên tiếp nhau và đổi chỗ chúng nếu chúng không theo thứ tự.
- Độ phức tạp: O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j + 1] < arr[j])
      {
        swap(arr[j + 1], arr[j]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

int main()
{
  vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
  bubble_sort(arr);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}