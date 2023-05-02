//chèn tìm kiếm phần tử trên cây
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node *left,*right;
};
// Hàm chèn một giá trị vào cây nhị phân tìm kiếm
struct Node* insert(struct Node* node, int key) {
    // Nếu cây rỗng, trả về một nút mới
    if (node == NULL) 
        return newNode(key);

    // Nếu khóa đã tồn tại, trả về nút hiện tại
    if (key == node->key) 
        return node;

    // Nếu khóa nhỏ hơn khóa của nút hiện tại, chèn vào cây con bên trái
    if (key < node->key) 
        node->left = insert(node->left, key);

    // Ngược lại, chèn vào cây con bên phải
    else 
        node->right = insert(node->right, key);

    // Trả về nút hiện tại
    return node;
}
//Hàm tìm kiếm phần tử trong cây nhị phân tìm kiếm:

// Hàm tìm kiếm một giá trị trong cây nhị phân tìm kiếm
struct Node* search(struct Node* root, int key) {
    // Nếu nút hiện tại là NULL hoặc khóa bằng với khóa cần tìm, trả về nút hiện tại
    if (root == NULL || root->key == key)
       return root;
    
    // Nếu khóa lớn hơn khóa của nút hiện tại, tìm trong cây con bên phải
    if (root->key < key)
       return search(root->right, key);
    
    // Ngược lại, tìm trong cây con bên trái
    return search(root->left, key);
}
