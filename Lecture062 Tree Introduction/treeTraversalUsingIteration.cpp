//Inorder Traversal
vector<int> inOrder(Node* root) {
      stack<Node *> s;
      vector<int>v;
      Node *curr = root;
      while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
  
       v.push_back(curr->data);
        curr = curr->right;
    } 
    return v;
    }

//Preorder Traversal
vector <int> preorder(Node* root)
{
  vector<int>v;
  stack<Node*>s;
  s.push(root);
 while(s.empty()==false)
 {
     struct Node* node = s.top();   
     v.push_back(node->data);
     s.pop();
     if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
 }
 return v;
}

//Postorder Traversal

void postoderUtil(Node* root , vector<int> &ans)
{
    if(!root) return;
    
    
    postoderUtil(root->left , ans);
    postoderUtil(root -> right , ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
  vector<int> ans;
  postoderUtil(root , ans);
  return ans;
}
