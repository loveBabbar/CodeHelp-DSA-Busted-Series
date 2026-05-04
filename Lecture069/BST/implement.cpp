#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;

    Node(int data) {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;
    
    // 2 4 1 9
    /*

                    2
                   / \
                  1   4
                     / \
                        9
        
    */
    Node* insertIntoBST(Node* currNode, int data) {

        if (currNode == NULL) {
            Node* newNode = new Node(data);
            return newNode;
        }

        if (data > currNode->data) {
            currNode->right = insertIntoBST(currNode->right, data);
        }
        else {
            currNode->left = insertIntoBST(currNode->left, data);
        }

        return currNode;
    }

    Node* deleteFromBST(Node* root, int val) {

        if (root == NULL) return NULL;

        if (root->data == val) {

            // ----------0 child------------
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // ---------1 child-----------
            // left
            if (root->left != NULL && root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // right
            if (root->right != NULL && root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            // ------------2 chindrens---------------
            if (root->left != NULL && root->right != NULL) {
                
                // either find max value in left part or min value in right part
                // lets find max one
                Node* pred = inorderPredecessor(val);

                // replace root-> data value by this max node value
                root->data = pred->data;

                // now delete this maximum value node from tree
                root->left = deleteFromBST(root->left, pred->data);
                return root;
            }
        }
        else if (root->data > val) {
            root->left = deleteFromBST(root->left, val);
            return root;
        }
        else {
            root->right = deleteFromBST(root->right, val);
            return root;
        }
    }

public:

    BinarySearchTree() {
        this->root = NULL;
    }

    void createBST(int data) {
        Node* temp = root;
        root = insertIntoBST(temp, data);
    }

    void takeInputForBST() {

        cout << "BST creation started...\n";
        cout << "enter data to push into BST, enter -1 to exit: ";

        int data;
        cin >> data;

        while (data != -1) {
            createBST(data);
            cin >> data;
        }

        cout << "\nBST created successfully\n";
    }

    int minVal() {

        if (root == NULL) return -1;

        Node* temp = root;
        while (temp->left) {
            temp = temp->left;
        }
        return temp->data;
    }

    int maxVal() {

        if (root == NULL) return -1;

        Node* temp = root;
        while (temp->right) {
            temp = temp->right;
        }
        return temp->data;
    }

    void deleteNode(int val) {
        root = deleteFromBST(root, val);
        cout << "deleted successfully\n";
    }
    /*

                    2
                   / \
                  1   4
                     / \
                        9
        
    */
    Node* searchInBST(Node *root, int x) {
        // Write your code here.

        if (root == NULL) {
            return NULL;
        }

        if (root->data == x) {
            return root;
        }

        if (root->data > x) {
            return searchInBST(root->left, x);
        }
        else {
            return searchInBST(root->right, x);
        }
    }

    Node* inorderPredecessor(int data) {

        // #1. point temp at required node
        Node* temp = root;
        temp = searchInBST(temp, data);
        
        // #2. find predecessor
        if (temp->left) {

            Node* pred = temp->left;
            while (pred->right) {
                pred = pred->right;
            }
            return pred;
        }
        return NULL;
    }

    Node* inorderSuccessor(int data) {

        // #1. point temp at required node
        Node* temp = root;
        temp = searchInBST(temp, data);
        
        // #2. find predecessor
        if (temp->right) {

            Node* succ = temp->right;
            while (succ->left) {
                succ = succ->left;
            }
            return succ;
        }
        return NULL;
    }

    void levelOrderTraversal() {

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            Node* temp = q.front();

            if (temp)
                cout << temp->data << " ";

            q.pop();

            if (temp == NULL) {
                cout << endl;

                if (!q.empty()) {
                    q.push(NULL);
                }
            }

            if (temp && temp->left) {
                q.push(temp->left);
            }

            if (temp && temp->right) {
                q.push(temp->right);
            }

        }
    }
};

int main() {

    BinarySearchTree bst;

    bst.takeInputForBST();
    bst.levelOrderTraversal();

    cout << "maximum: " << bst.maxVal() << endl;
    cout << "minimum: " << bst.minVal() << endl;

    Node* pred = bst.inorderPredecessor(21);
    cout << "inorder predecessor is: " << pred->data << endl;

    Node* succ = bst.inorderSuccessor(21);
    cout << "inorder Successor is: " << succ->data << endl;

    bst.deleteNode(21);
    bst.levelOrderTraversal();

    return 0;
}