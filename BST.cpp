#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to Insert a Node in BST
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);

    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);

    return root;
}

// Function to Search for a Key in BST
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

// Function to Find Minimum Value in BST
Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// Function to Delete a Node in BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function for Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function for Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function for Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }
}

// Main Function with User Input
int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\nBinary Search Tree Operations:";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Inorder Traversal";
        cout << "\n5. Preorder Traversal";
        cout << "\n6. Postorder Traversal";
        cout << "\n7. Level Order Traversal";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) cout << "Value found in BST.";
                else cout << "Value not found.";
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Level Order Traversal: ";
                levelOrderTraversal(root);
                cout << endl;
                break;
            case 8:
                cout << "Exiting program.";
                return 0;
            default:
                cout << "Invalid choice. Please try again.";
        }
    }
}
