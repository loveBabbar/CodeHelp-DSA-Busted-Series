#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
private:
    void insertUtil(TrieNode* root, string word) {

        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {

        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch < 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];

            if (next) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);

                // pop last one while backtracking
                prefix.pop_back();
            }
        }
    }

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char last_ch = str[i];
            prefix.push_back(last_ch);

            // check for last charceter
            TrieNode* curr = prev->children[last_ch - 'a'];

            // no word like this
            if (curr == NULL) {
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // ------create a trie-----------
    Trie t;

    // -----insert all contacts in trie---------
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t.insertWord(str);
    }

    return t.getSuggestions(queryStr);
}