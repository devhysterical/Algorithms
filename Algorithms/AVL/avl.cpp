#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
  int height;
};

int height(node *root)
{
  if (root == NULL)
    return 0;
  return root->height;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

node *newNode(int data)
{
  node *temp = new node();
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  temp->height = 1;
  return temp;
}

node *rightRotate(node *y)
{
  node *x = y->left;
  node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

node *leftRotate(node *x)
{
  node *y = x->right;
  node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(node *root)
{
  if (root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

node *insert(node *root, int data)
{
  if (root == NULL)
    return newNode(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  else
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  if (balance > 1 && data < root->left->data)
    return rightRotate(root);

  if (balance < -1 && data > root->right->data)
    return leftRotate(root);

  if (balance > 1 && data > root->left->data)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && data < root->right->data)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preOrder(node *root)
{
  if (root != NULL)
  {
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}

void postOrder(node *root)
{
  if (root != NULL)
  {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
  }
}

int main()
{
  node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  cout << "Preorder traversal of the constructed AVL tree is: ";
  preOrder(root);
  cout << endl;
  cout << "Inorder traversal of the constructed AVL tree is: ";
  inOrder(root);
  cout << endl;
  cout << "Postorder traversal of the constructed AVL tree is: ";
  postOrder(root);
  cout << endl;
  system("pause");
  return 0;
}