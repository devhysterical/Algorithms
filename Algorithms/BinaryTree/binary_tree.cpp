#include <bits/stdc++.h>
using namespace std;
// Cấu trúc dữ liệu của một nút trong cây nhị phân
struct Node
{
  int data;           // Dữ liệu của nút
  Node *left, *right; // Con trỏ trái, phải
};
// Hàm tạo một nút mới
Node *newNode(int data)
{
  Node *node = new Node; // Cấp phát bộ nhớ cho nút mới
  node->data = data;     // Gán dữ liệu cho nút mới
  node->left = NULL;     // Con trỏ trái = NULL
  node->right = NULL;    // Con trỏ phải = NULL
  return node;           // Trả về nút mới
}
// Hàm tạo cây nhị phân
Node *createTree()
{
  Node *root = newNode(1);        // Tạo nút gốc
  root->left = newNode(2);        // Tạo nút con trái
  root->right = newNode(3);       // Tạo nút con phải
  root->left->left = newNode(4);  // Tạo nút con trái của nút con trái
  root->left->right = newNode(5); // Tạo nút con phải của nút con trái
  return root;                    // Trả về nút gốc
}
// Hàm duyệt cây nhị phân theo thứ tự trước
void preOrder(Node *root)
{
  if (root != NULL)
  {
    cout << root->data << " "; // Xử lý dữ liệu của nút gốc
    preOrder(root->left);      // Duyệt cây con trái
    preOrder(root->right);     // Duyệt cây con phải
  }
}
// Hàm duyệt cây nhị phân theo thứ tự giữa
void inOrder(Node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);       // Duyệt cây con trái
    cout << root->data << " "; // Xử lý dữ liệu của nút gốc
    inOrder(root->right);      // Duyệt cây con phải
  }
}
// Hàm duyệt cây nhị phân theo thứ tự sau
void postOrder(Node *root)
{
  if (root != NULL)
  {
    postOrder(root->left);     // Duyệt cây con trái
    postOrder(root->right);    // Duyệt cây con phải
    cout << root->data << " "; // Xử lý dữ liệu của nút gốc
  }
}
int main()
{
  Node *root = createTree(); // Tạo cây nhị phân
  cout << "Preorder: ";
  preOrder(root); // Duyệt cây nhị phân theo thứ tự trước
  cout << endl;
  cout << "Inorder: ";
  inOrder(root); // Duyệt cây nhị phân theo thứ tự giữa
  cout << endl;
  cout << "Postorder: ";
  postOrder(root); // Duyệt cây nhị phân theo thứ tự sau
  cout << endl;
  return 0;
}