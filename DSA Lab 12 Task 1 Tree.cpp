#include <iostream>
using namespace std;
class node {
public:
    int data;
    node *left;
    node *right;
    // Default constructor
    node(){
    	data=0;
    	left=NULL;
    	right=NULL;
	}
    // Parameterized constructor
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    // Preorder traversal (Root, Left, Right)
    void preorder(node *ptr) {
        if (ptr != NULL) {
            cout << ptr->data << " ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }
    // Inorder traversal (Left, Root, Right)
    void inorder(node *ptr) {
        if (ptr != NULL) {
            inorder(ptr->left);
            cout << ptr->data << " ";
            inorder(ptr->right);
        }
    }
    // Postorder traversal (Left, Right, Root)
    void postorder(node *ptr) {
        if (ptr != NULL) {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->data << " ";
        }
    }
};
int main() {
    // Creating the tree structure
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->right->left = new node(8);
    root->right->right = new node(7);
    node n;
    cout << "Preorder traversal: ";
    n.preorder(root);
    cout << endl;
    cout << "Inorder traversal: ";
    n.inorder(root);
    cout << endl;
    cout << "Postorder traversal: ";
    n.postorder(root);
    cout << endl;
    return 0;
}