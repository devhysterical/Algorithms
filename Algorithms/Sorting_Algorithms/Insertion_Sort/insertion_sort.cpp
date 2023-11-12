/*
- Insertion Sort (sắp xếp chèn) sắp xếp dãy số bằng cách chèn lần lượt từng phần tử vào đúng vị trí của nó trong dãy đã sắp xếp.
- Độ phức tạp: O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertion_sort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
  insertion_sort(arr);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}