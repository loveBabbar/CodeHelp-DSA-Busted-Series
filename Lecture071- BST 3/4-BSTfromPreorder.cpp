#include <bits/stdc++.h> 
using namespace std;
template<typename T>

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };


BinaryTreeNode<int>* solve(vector<int> &pre,int mini, int maxi, int &i){
        // cout << 1 ;
    if(i >= pre.size()){
        return NULL;
    }
    if(pre[i] > maxi || pre[i] < mini)
        return NULL;


        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[i++]);
        root -> left = solve(pre,mini,root -> data,i);
        root -> right = solve(pre,root -> data,maxi,i);
        return root;
 
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {

    int maxi = INT_MAX, mini = INT_MIN,i=0;
    return solve(preorder,mini,maxi,i);
}