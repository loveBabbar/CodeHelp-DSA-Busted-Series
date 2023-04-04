/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{

private:
    Node *mappingToparent(Node *root, unordered_map<int, Node *> &mp, int target)
    {

        Node *ans;

        queue<Node *> q;
        q.push(root);
        mp[root->data] = NULL;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                mp[temp->left->data] = temp;
            }
            if (temp->right)
            {
                q.push(temp->right);
                mp[temp->right->data] = temp;
            }

            if (temp->data == target)
                ans = temp;
        }
        return ans;
    }

    int solve(Node *root, unordered_map<int, Node *> mp)
    {

        int ans = 0;
        unordered_set<int> visited;

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {

            int siz = q.size();

            bool flag = 0;
            while (siz > 0)
            {
                Node *temp = q.front();
                q.pop();
                siz--;

                if (temp->left && visited.find(temp->left->data) == visited.end())
                {
                    q.push(temp->left);
                    visited.insert(temp->left->data);
                    flag = 1;
                }

                if (temp->right && visited.find(temp->right->data) == visited.end())
                {
                    q.push(temp->right);
                    visited.insert(temp->right->data);
                    flag = 1;
                }
                Node *parent = mp[temp->data];

                if (parent == NULL)
                    continue;

                if (visited.find(parent->data) == visited.end())
                {
                    q.push(parent);
                    visited.insert(parent->data);
                    flag = 1;
                }
            }

            if (flag == 1)
                ans++;
        }

        return ans;
    }

public:
    int minTime(Node *root, int target)
    {
        unordered_map<int, Node *> nodeToparent;
        Node *burnode = mappingToparent(root, nodeToparent, target);
        int ans = solve(burnode, nodeToparent);
        return ans;
    }
};