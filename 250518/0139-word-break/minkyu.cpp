#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string word;
    vector<Node*> children;

    Node() {
        this->word = "";
        this->children = vector<Node*>(26, nullptr);
    }

    void collectPrefixes(string s, int idx, vector<string>& prefixes) {
        if (this->word.empty()) prefixes.push_back(this->word);
        if (s.size() == idx) return;
        Node* child = this->get(s[idx]);
        if (child != nullptr) child->collectPrefixes(s, idx+1, prefixes);
    }

    Node* get(char c) {
        return this->children[c - 'a'];
    }

    void add(string s) {
        this->add(s, 0);
    }

    void add(string s, int idx) {
        if (s.size() == idx) {
            this->word = s;
            return;
        }
        char c = s[idx];
        Node* child = this->children[c - 'a'];
        if (child == nullptr) {
            child = new Node();
            this->children[c - 'a'] = child;
        }
        child->add(s, idx + 1);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Node* root = new Node();
        for (auto& word: wordDict) {
            root->add(word);
        }

        return this->wordBreak(s, root, 0);
    }

    bool wordBreak(string s, Node* node, int idx) {
        vector<string> prefixes;
        node->collectPrefixes(s, idx, prefixes);
        for (auto& prefix: prefixes) {
            int new_idx = idx + prefix.size();
            if (new_idx == s.size()) return true;
            else if (wordBreak(s, node, new_idx)) return true;
        }
        return false;
    }
};
