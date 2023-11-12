/*
- Selection Sort (sắp xếp chọn) sắp xếp dãy số bằng cách tìm phần tử nhỏ nhất trong dãy và đưa nó về đầu dãy.
- Độ phức tạp: O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selection_sort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_idx])
      {
        min_idx = j;
      }
    }
    swap(arr[i], arr[min_idx]);
  }
}

int main()
{
  vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
  selection_sort(arr);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}