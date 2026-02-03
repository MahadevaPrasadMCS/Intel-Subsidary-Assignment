#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree {
private:
    Node *root;
    Node *NIL;

    Node* createNode(int data) {
        Node* node = new Node;
        node->data = data;
        node->color = RED;
        node->left = NIL;
        node->right = NIL;
        node->parent = NULL;
        return node;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != NIL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != NIL)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == NULL)
            root = x;
        else if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;

        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* z) {
        while (z->parent != NULL && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void inorder(Node* node) {
        if (node == NIL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    RedBlackTree() {
        NIL = new Node;
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL;
        NIL->parent = NULL;
        root = NIL;
    }

    void insert(int data) {
        Node* z = createNode(data);
        Node* y = NULL;
        Node* x = root;

        while (x != NIL) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;

        if (y == NULL)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        fixInsert(z);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Inorder traversal: ";
    tree.display();

    return 0;
}
