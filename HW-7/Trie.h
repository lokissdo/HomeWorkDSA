#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

struct TrieNode {
    int m_count; // Number of words that end at a node.
    int m_ID; // Index of a word, read from dictionary text file.

    TrieNode* m_next[26];
};

// struct Trie {TrieNode *root;};

TrieNode* makeNode();

void createTrie(TrieNode* &root, string FileName);

void Insert(TrieNode* root, string word, int ID);

int lookUp(TrieNode* root, string word);

vector<string> lookUpPrefix(TrieNode* root, string prefix);

void dfs(TrieNode* root, string cur, vector<string> &words);

void Remove(TrieNode* &root, string word);

bool isLeafNode(TrieNode* node);