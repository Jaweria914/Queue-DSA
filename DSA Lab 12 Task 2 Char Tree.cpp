#include <iostream>
using namespace std;
class node {
public:
    char data;
    node *left;
    node *right;
    // Default constructor
    node(){
    	data=0;
    	left=NULL;
    	right=NULL;
	}
    // Parameterized constructor
    node(char data) {
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
    node *root = new node('A');
    root->left = new node('B');
    root->right = new node('C');
    root->left->left = new node('D');
    root->left->right = new node('E');
    root->right->left = new node('F');
    root->right->right = new node('G');
    root->left->left->left = new node('H');
    root->left->left->right = new node('I');
    root->left->right->left = new node('J');
    root->left->right->right = new node('K');
    root->right->left->right = new node('L');
    root->right->right->left = new node('M');
    
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