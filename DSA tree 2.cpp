#include <iostream>

using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;
    
    Employee(int id, string name, double salary) 
        : id(id), name(name), salary(salary) {}
};

class Tree {
public:
    Employee* employee;
    Tree* left;
    Tree* right;

    Tree(Employee* emp) : employee(emp), left(NULL), right(NULL) {}
};

class EmployeeBST {
private:
    Tree* root;

    Tree* insert(Tree* node, Employee* emp) {
        if (!node) return new Tree(emp);
        if (emp->id < node->employee->id)
            node->left = insert(node->left, emp);
        else if (emp->id > node->employee->id)
            node->right = insert(node->right, emp);
        return node;
    }

    Tree* search(Tree* node, int id) {
        if (!node || node->employee->id == id)
            return node;
        return (id < node->employee->id) ? search(node->left, id) : search(node->right, id);
    }

    Tree* deleteNode(Tree* node, int id) {
        if (!node) return node;
        if (id < node->employee->id)
            node->left = deleteNode(node->left, id);
        else if (id > node->employee->id)
            node->right = deleteNode(node->right, id);
        else {
            if (!node->left) {
                Tree* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Tree* temp = node->left;
                delete node;
                return temp;
            }
            
            // Find the in-order successor (smallest node in the right subtree)
            Tree* successor = node->right;
            while (successor->left) {
                successor = successor->left;
            }

            node->employee = successor->employee;
            node->right = deleteNode(node->right, successor->employee->id);
        }
        return node;
    }

    void inorder(Tree* node) {
        if (node) {
            inorder(node->left);
            displayEmployee(node->employee);
            inorder(node->right);
        }
    }

    void displayEmployee(Employee* emp) {
        cout << "ID: " << emp->id << ", Name: " << emp->name << ", Salary: " << emp->salary << endl;
    }

public:
    EmployeeBST() : root(NULL) {}

    void insert(int id, string name, double salary) {
        root = insert(root, new Employee(id, name, salary));
    }

    void search(int id) {
        Tree* result = search(root, id);
        if (result) {
            cout << "Employee Found: ";
            displayEmployee(result->employee);
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void deleteEmployee(int id) {
        root = deleteNode(root, id);
    }

    void displayInorder() {
        cout << "In-order Traversal:" << endl;
        inorder(root);
    }
};

int main() {
    EmployeeBST bst;
    
    bst.insert(1, "AAA", 11111);
    bst.insert(2, "BBB", 22222);
    bst.insert(3, "CCC", 33333);
    bst.insert(4, "DDD", 44444);

    bst.displayInorder();

    bst.search(1);
    bst.search(5);

    bst.deleteEmployee(4);
    cout << "After deleting employee:" << endl;
    bst.displayInorder();

    return 0;
}
