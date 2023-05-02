#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút của cây
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Hàm tạo một nút mới trong cây
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm thêm một nút mới vào cây
struct Node* insertNode(struct Node* node, int data) {
    // Nếu cây rỗng, trả về một nút mới
    if (node == NULL) {
        return createNode(data);
    }
    // Nếu giá trị dữ liệu của nút lớn hơn giá trị dữ liệu của nút hiện tại,
    // thêm nút mới vào cây con phải
    if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    // Ngược lại, thêm nút mới vào cây con trái
    else {
        node->left = insertNode(node->left, data);
    }
    return node;
}

// Hàm duyệt cây theo thứ tự in-order
void inOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    inOrderTraversal(node->left);
    
    inOrderTraversal(node->right);
}

// Hàm đọc dữ liệu từ file và tạo cây nhị phân tìm kiếm
struct Node* buildTreeFromFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Khong mo duoc file");
        return NULL;
    }
    int value;
    struct Node* root = NULL;
    while (fscanf(fp, "%d", &value) != EOF) {
        root = insertNode(root, value);
    }
    fclose(fp);
    return root;
}

int main() {
    // Tạo cây từ file
    struct Node* root = buildTreeFromFile("nhap2.txt");

    // Duyệt cây theo thứ tự in-order và xuất ra màn hình
    printf("Cay nhi phan tim kiem: ");
    inOrderTraversal(root);

    return 0;
}
