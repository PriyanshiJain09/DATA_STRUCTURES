#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* root, int key) {
        if (root == NULL) {
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRec(root->left, key);
        }
        else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

    Node* searchRec(Node* root, int key) {
        if (root == NULL || root->key == key) {
            return root;
        }
        if (key < root->key) {
            return searchRec(root->left, key);
        }
        return searchRec(root->right, key);
    }

    Node* deleteRec(Node* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteRec(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteRec(root->right, key);
        }
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRec(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void preorderRec(Node* root) {
        if (root != NULL) {
            cout << root->key << ' ';
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void inorderRec(Node* root) {
        if (root != NULL) {
            inorderRec(root->left);
            cout << root->key << ' ';
            inorderRec(root->right);
        }
    }

    void postorderRec(Node* root) {
        if (root != NULL) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->key << ' ';
        }
    }

    int getHeightRec(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = getHeightRec(root->left);
        int rightHeight = getHeightRec(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int findMinValueRec(Node* root) {
        Node* current = root;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current->key;
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    bool search(int key) {
        return searchRec(root, key) != NULL;
    }

    void remove(int key) {
        root = deleteRec(root, key);
    }

    void preorder() {
        preorderRec(root);
    }

    void inorder() {
        inorderRec(root);
    }

    void postorder() {
        postorderRec(root);
    }

    int getHeight() {
        return getHeightRec(root);
    }

    int findMinValue() {
        return findMinValueRec(root);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, key;
    while (true) {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Search for an element\n";
        cout << "3. Delete an element\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Inorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Get Tree Height\n";
        cout << "8. Get Minimum Value\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> key;
            bst.insert(key);
            break;
        case 2:
            cout << "Enter the element to search: ";
            cin >> key;
            if (bst.search(key)) {
                cout << "Element " << key << " found in the tree.\n";
            }
            else {
                cout << "Element " << key << " not found in the tree.\n";
            }
            break;
        case 3:
            cout << "Enter the element to delete: ";
            cin >> key;
            bst.remove(key);
            break;
        case 4:
            cout << "Preorder Traversal: ";
            bst.preorder();
            cout << endl;
            break;
        case 5:
            cout << "Inorder Traversal: ";
            bst.inorder();
            cout << endl;
            break;
        case 6:
            cout << "Postorder Traversal: ";
            bst.postorder();
            cout << endl;
            break;
        case 7:
            cout << "Tree Height: " << bst.getHeight() << endl;
            break;
        case 8:
            cout << "Minimum Value in the Tree: " << bst.findMinValue() << endl;
            break;
        case 9:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

