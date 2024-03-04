#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

Node *buildTree(int in[], int post[], int n) {
    if( n == 0){
        return NULL;
    }
    
    if(n == 1){
        Node* ans = new Node(post[n-1]);
        return ans;
    }
    
    Node* ans = new Node(post[n-1]);

    // ! to optimize we can use map
    // !     |
    // !    \/ 
    int i = 0;
    while( in[i] != post[n-1]){
        i++;
    }
    
    ans -> left = buildTree(in,post,i);
    ans -> right = buildTree(in+i+1,post+i,n-i-1);
    
    return ans;
}
