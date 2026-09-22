#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/// Câu 1
struct SinhVien
{
    int maSV;
    char tenSV[25];
    char lop[15];
    float diemTK;
    char hanhKiem[10];
};
/// H?t Câu 1

typedef SinhVien Data;

Data NhapData()
{
    Data data;
    
    printf("  + Nhap ma sinh vien: ");
    scanf("%d", &data.maSV);
    
    printf("  + Nhap ten sinh vien: ");
    fflush(stdin);
    gets(data.tenSV);
    
    printf("  + Nhap lop: ");
    fflush(stdin);
    gets(data.lop);
    
    printf("  + Nhap diem tong ket: ");
    scanf("%f", &data.diemTK);
    
    printf("  + Nhap hanh kiem: ");
    fflush(stdin);
    gets(data.hanhKiem);
    
    return data;
}

/// Câu 2
struct Node
{
    Data data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *BinaryTree;
typedef struct Node *NodePtr;

///// In thông tin c?a m?t nút
void PrintNode(NodePtr pnode)
{
    printf("  + Ma sinh vien: %d; Ten sinh vien: %s; Lop: %s; Diem tong ket: %f; Hanh kiem: %s\n",
           pnode->data.maSV, pnode->data.tenSV, pnode->data.lop, pnode->data.diemTK, pnode->data.hanhKiem);
}

///// Kh?i t?o
void initialize(BinaryTree &T)
{
    T = NULL;
}

///// T?o m?t nút
NodePtr createNode(Data data) {
    NodePtr newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void insertToTree(BinaryTree &T, Data data)
{
    NodePtr q;
    if (T == NULL)
    {
        q = createNode(data);
        T = q;
    }
    else if (data.maSV < T->data.maSV)
        insertToTree(T->left, data);
    else if (data.maSV > T->data.maSV)
        insertToTree(T->right, data);
}

NodePtr search(int maSV, BinaryTree T)
{
    NodePtr p;
    p = T;
    if (p != NULL)
    {
        if (maSV < p->data.maSV)
            return search(maSV, p->left);
        else if (maSV > p->data.maSV)
            return search(maSV, p->right);
        else return p;
    }
    else return NULL;
}

void preOrder(BinaryTree T)
{
    if (T != NULL)
    {
        PrintNode(T);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void inOrder(BinaryTree T)
{
    if (T != NULL)
    {
        inOrder(T->left);
        PrintNode(T);
        inOrder(T->right);
    }
}

void postOrder(BinaryTree T)
{
    if (T != NULL)
    {
        postOrder(T->left);
        postOrder(T->right);
        PrintNode(T);
    }
}
/// H?t Câu 2

int main()
{
    /// Câu 3
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    
    BinaryTree T;
    initialize(T);
    
    for (int i = 0; i < n; i++)
    {
        cout << "-> Nhap thong tin sinh " << i + 1 << ":" << endl;
        Data data = NhapData();
        insertToTree(T, data);
    }
    /// H?t Câu 3
    
    /// Câu 4
    cout << "===> Danh sach du lieu vua nhap (PreOder): " << endl;
    preOrder(T);
    
    cout << endl << "===> Danh sach du lieu vua nhap (InOder): " << endl;
    inOrder(T);
    
    cout << endl << "===> Danh sach du lieu vua nhap (PostOder): " << endl;
    postOrder(T);
    /// H?t Câu 4
    
    /// Câu 5:
    int maSV;
    printf("Nhap ma sinh vien can tim: ");
    scanf("%d", &maSV);
    
    NodePtr found = search(maSV, T);
    if (found == NULL) printf("-> Khong tim thay sinh vien co ma la: %d\n", maSV);
    else
    {
        printf("-> Tim thay sinh vien co ma: %d\n", maSV);
        PrintNode(found);
    }
    /// H?t Câu 5
    
    return 0;
}
