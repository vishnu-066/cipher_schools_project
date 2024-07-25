#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;
    BST() : root(NULL) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    bool searchRec(Node* node, int value) {
        if (node == NULL) {
            return false;
        }
        if (value == node->data) {
            return true;
        }
        if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }

    Node* deleteRec(Node* root, int key) {
        if (root == NULL) return root;
        if (key < root->data) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->data) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void inorderRec(Node* root) {
        if (root != NULL) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }

    void preorderRec(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void postorderRec(Node* root) {
        if (root != NULL) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    BST tree;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << value << " found in the tree.\n";
            } else {
                cout << value << " not found in the tree.\n";
            }
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteNode(value);
            break;
        case 4:
            cout << "Inorder traversal: ";
            tree.inorder();
            break;
        case 5:
            cout << "Preorder traversal: ";
            tree.preorder();
            break;
        case 6:
            cout << "Postorder traversal: ";
            tree.postorder();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

