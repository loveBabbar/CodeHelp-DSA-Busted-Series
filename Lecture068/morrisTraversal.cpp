#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;

    Node (int data) {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }
};

class BinaryTree{
private:
    Node* root;

    Node* buildTree(Node* root) {

        int data;
        cout << "Enter the data: ";
        cin >> data;

        if (data == -1) {
            return NULL;
        }

        root = new Node(data);

        cout << "Enter the data for left of " << data << " ";
        root->left = buildTree(root->left);
        cout << "Enter the data for right of " << data << " ";
        root->right = buildTree(root->right);
        return root;
    }

    Node* createDemoTree(int depth) {

        // Base case
        if (depth == 0) return NULL;

        // Create node with random value (1–100)
        Node* root = new Node(rand() % 20 + 1);

        // Recursively create left & right subtrees
        root->left = createDemoTree(depth - 1);
        root->right = createDemoTree(depth - 1);

        return root;
    }

    void inorder(Node* root) {

        if (root == NULL) {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {

        if (root == NULL) {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {

        if (root == NULL) {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
public:

    void createTree() {
        cout << "Tree creation starts...\n";
        root = buildTree(root);
        cout << "\nTree created successfully\n";
    }

    Node* findPredecessor(Node* curr) {

        Node* pred = curr->left;
        while (pred->right && pred->right != curr) {
            pred = pred->right;
        }
        return pred;
    }

    // ----------------MORRIS TRAVERSAL--------------
    void morrisTraversal() {

        std::cout << "\nprinting in inorder using morris traversal:\n";
        Node* current = root;
        while (current != NULL) {

            // If no left child, visit this node 
            // and go right
            if (current->left == NULL) {
                std::cout << current->data << " ";
                current = current->right;
            }
            else {

                // Find the inorder predecessor of curr
                Node* predecessor = findPredecessor(current);

                // Make curr the right child of its 
                // inorder predecessor
                if (predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                }
                else {
                    // Revert the changes made in 
                    // the tree structure
                    predecessor->right = NULL;
                    std::cout << current->data << " ";
                    current = current->right;
                }
            }
        }
        std::cout << std::endl;
    }
    // ----------------------------------------------

    void dummyTree(int depth) {
        root = createDemoTree(depth);
    }

    void levelOrderTraversal() {

        queue<Node*> q;
        q.push(root);
        q.push(NULL); // seperator

        // q -> |..|
        // 1 3 5 7 11 17 

        while (!q.empty()) {
            Node* temp = q.front();

            if (temp)
                cout << temp->data << " ";

            q.pop();

            // seperator
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

    void inOrder() {

        Node* temp = root;
        inorder(temp);
    }

    void preOrder() {

        Node* temp = root;
        preorder(temp);
    }

    void postOrder() {

        Node* temp = root;
        postorder(temp);
    }

    void buildFromLevelOrder() {

        queue<Node*> q;
        
        int rootData;
        cout << "data for root: ";
        cin >> rootData;

        root = new Node(rootData);
        q.push(root);

        while (!q.empty()) {

            Node* temp = q.front();
            q.pop();

            int leftData;
            cout << "data for left of: " << temp->data << ": ";
            cin >> leftData;

            if (leftData != -1) {

                temp->left = new Node(leftData);
                q.push(temp->left);
            }

            int rightData;
            cout << "data for right of: " << temp->data << ": ";
            cin >> rightData;

            if (rightData != -1) {

                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }
};

int main() {

    BinaryTree bt;

    bt.buildFromLevelOrder();

    // bt.inOrder();

    bt.morrisTraversal();

    return 0;
}