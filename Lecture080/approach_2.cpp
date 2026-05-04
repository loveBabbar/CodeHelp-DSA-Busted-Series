#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {

        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in uppercase
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recurssion
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {

        TrieNode* temp = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            int index = ch - 'a';

            if (temp->childCount == 1 && temp->children[index] != NULL) {
                ans.push_back(ch);
                temp = temp->children[index];
            }
            else {
                break;
            }

            if (temp->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    for (int i = 0; i < n; i++) {
        t->insert(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}


