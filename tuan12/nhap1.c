#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

//Tạo nút mới
struct node *new_node(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

//Duyệt cây theo thứ tự inorder
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

//Thêm nút mới
struct node *add_node(struct node *node, int data) {
  if (node == NULL) return new_node(data);

  if (data < node->data)
    node->left = add_node(node->left, data);
  else
    node->right = add_node(node->right, data);

  return node;
}

//Tìm kiếm nút kế nhiệm
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Xóa nút
struct node *remove_node(struct node *root, int data) {
  // Trả về nếu nút là rỗng
  if (root == NULL) return root;

  // Tìm nút cần xóa
  if (data < root->data)
    root->left = remove_node(root->left, data);
  else if (data > root->data)
    root->right = remove_node(root->right, data);

  else {
    // Nếu nút chỉ có 1 hoặc không có nút con nào
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Nếu nút có 2 nút con
    struct node *temp = minValueNode(root->right);

    // Đặt nút kế nhiệm vào nút cần xóa
    root->data = temp->data;

    // Xóa nút kế nhiệm
    root->right = remove_node(root->right, temp->data);
  }
  return root;
}

int main() {
  struct node *root = NULL;
  root = add_node(root, 42);
  root = add_node(root, 12);
  root = add_node(root, 21);
  root = add_node(root, 20);
  root = add_node(root, 100);
  root = add_node(root, 9);
  printf("\nDuyệt cây theo thứ tự Inorder\n");
  inorder(root);

  printf("\nDuyệt cây theo thứ tự Inorder sau khi xóa nút có giá trị là 20\n");
  root = remove_node(root, 20);
  inorder(root);
}