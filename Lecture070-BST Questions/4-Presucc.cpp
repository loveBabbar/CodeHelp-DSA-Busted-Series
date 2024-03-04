#include<iostream>
#include<vector>
using namespace std;

 class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};




pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    vector<int> ans;
    TreeNode* q = root;
    int i;
    ans.push_back(-1);
    while(q != NULL){
        if(q -> left == NULL){
            if (q->data <= key) {
              i = ans.size();
            }
            ans.push_back(q -> data);
            // cout << q -> data << " ";
            q = q-> right; 
        }
        else{
            TreeNode* temp = q -> left;
            while(temp -> right != NULL && temp -> right != q){
            temp = temp -> right;
            }
            if(temp -> right == NULL){
            temp -> right = q;        
              q = q -> left;
            }
            else{
            if (q->data <= key) {
              i = ans.size();
            }
                // ans.push_back(temp->data);
                // cout << temp -> data << " ";
                // cout << q -> data << " ";
                ans.push_back(q->data);
                q = q -> right;
                temp->right = NULL;
            }
        }
    }
        ans.push_back(-1);
        // for( int i = 0; i < ans.size(); i++)
        // cout << ans [i] << " ";

        // cout<< endl << i << endl;
        if(ans[i] == key)
        return{ans[i-1],ans[i+1]};

        return{ans[i],ans[i+1]};
        
}