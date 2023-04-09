
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int find(int in[], int target, int start, int end){
    for(int i=start; i<=end; i++){
        if(in[i]==target)
            return i;
    }
    return -1;
}

Node* solve(int in[], int post[], int& postindex, int instart, int inend, int n){
    
    //base case
    if(postindex<0 || instart > inend){
        return NULL;
    }
    
    int element = post[postindex--];//find element in inorder array
    Node* root = new Node(element);//creating new node
    int position = find(in,element,instart,inend);

    //recursive call but note postorder hence call for right subtree is first then left subtree
    root->right = solve(in, post, postindex, position+1, inend, n);
    root->left = solve(in, post, postindex, instart, position-1, n);
    
    return root;
}



//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postindex = n-1;
    Node* root = solve(in,post,postindex,0,n-1,n);
    return root;
}