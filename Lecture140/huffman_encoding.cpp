// https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;
    
    Node(int d, Node* left, Node* right) {
        this->left = left;
        data = d;
        this->right = right;
    }
};

class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};


class Solution {
  public:
    
    void traverse(Node* root, vector<string>& ans, string temp) {
        
        // leag node-> charecter frequency
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
            return;
        }
        
        traverse(root->left, ans, temp+'0');
        traverse(root->right, ans, temp+'1');
    }
    
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        
        // create a min heap
        priority_queue<Node*, vector<Node*>, cmp> min_heap;
        
        // push all frequency in min_heap
        for (int i = 0; i < N; i++) {
            Node* temp = new Node(f[i], nullptr, nullptr);
            min_heap.push(temp);
        }
        
        while (min_heap.size() > 1) {
            
            // pop two smallest frequency chars from min_heap
            Node* left = min_heap.top();
            min_heap.pop();
            
            Node* right = min_heap.top();
            min_heap.pop();
            
            // add these two nodes and append result in heap
            int new_node_data = left->data + right->data;
            Node* new_node = new Node(new_node_data, left, right);
            
            min_heap.push(new_node);
        }
        
        // min_heap will conatin only one element at the end
        Node* root = min_heap.top();
        
        vector<string> ans;
        string temp = "";
        traverse(root, ans, temp);
        return ans;
    }
};