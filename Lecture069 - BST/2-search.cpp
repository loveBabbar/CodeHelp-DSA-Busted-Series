#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root != NULL){
        int t = root -> data;
        if( t == x){
            return true;
        }
        else if( t > x){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }

    return false;
}

int main(){
    


return 0;
}