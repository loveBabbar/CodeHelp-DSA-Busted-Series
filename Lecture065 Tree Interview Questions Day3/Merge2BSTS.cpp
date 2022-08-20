#include<bits/stdc++.h>
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
//STEP1
void  convertBSTtoDLL(TreeNode<int> *root,TreeNode<int>*&head){
    if(root==NULL)
        return ;
    convertBSTtoDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertBSTtoDLL(root->left,head);
}

//*****************************************************************************/

//STEP 2
TreeNode<int> *mergeDLL(TreeNode<int>*head1,TreeNode<int>*head2){
    TreeNode<int>*head=NULL;
    TreeNode<int>*tail=NULL;
    while(head1!=NULL and head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                head1->left=tail;
                tail->right=head1;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                  head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                head2->left=tail;
                tail->right=head2;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        head1->left=tail;
                tail->right=head1;
                tail=head1;
                head1=head1->right;
    }
    while(head2!=NULL){
          head2->left=tail;
                tail->right=head2;
                tail=head2;
                head2=head2->right;
    }
    return head;
}
/*********************************************************************************************/

//STEP3 Converting DLL to a Tree

int count(TreeNode<int> *root){
    int cnt=0;
    while(root!=NULL)
    {
        cnt++;
        root=root->right;
    }
    return cnt;
}
TreeNode<int> *sortedDLLtoBST(TreeNode<int>*&head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode<int>* left=sortedDLLtoBST(head,n/2);
      TreeNode<int>*  root=head;
     root->left=left;
    head=head->right;
    root->right=sortedDLLtoBST(head,n-n/2-1);
    return root;
}

//Main Function
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
/********************************************************************************/    
    // STEP1 converting BST to Doubly Linked List
    
TreeNode<int>*head1=NULL;
    convertBSTtoDLL(root1,head1);
    head1->left=NULL;
    TreeNode<int>*head2=NULL;
    convertBSTtoDLL(root2,head2);
    head2->left=NULL;
    
    /************************************************************************/
    
    /***************************************************************************/
    // STEP2 Merging the list
    TreeNode<int>*head=mergeDLL(head1,head2);
    //STEP3 Converting Doubly linked list to tree
    int nodes=count(head);
    return sortedDLLtoBST(head,nodes);
}
