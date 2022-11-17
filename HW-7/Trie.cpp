#include "Trie.h"

TrieNode* makeNode() {
    TrieNode* node = new TrieNode;
    node->m_count = 0;
    node->m_ID = 0;

    for (int i = 0; i < 26; i++) {
        node->m_next[i] = nullptr;
    }

    return node;
}

void createTrie(TrieNode* &root, string FileName) {
    ifstream inp;
    inp.open(FileName, ios::in);

    if (!inp.good()) {
        return;
    }

    root = makeNode();

    string str;
    while (getline(inp, str)) {
        stringstream parser(str);

        parser >> str;
        str.pop_back(); // remove the '.' at the back of the ID term
        int ID = stoi(str);

        parser >> str;

        Insert(root, str, ID);
    }

    inp.close();
}

void Insert(TrieNode* root, string word, int ID) {
    int wordSize = word.size();

    TrieNode* p = root;
    for (int i = 0; i < wordSize; i++) {
        int ord = word[i] - 'a';
        if (p->m_next[ord] == nullptr) {
            p->m_next[ord] = makeNode();
        }
        p = p->m_next[ord];
    }

    p->m_count++;
    if (p->m_ID == 0) {
        p->m_ID = ID; // only keep the ID of the first word inserted to trie
    }
}

int lookUp(TrieNode* root, string word) {
    int wordSize = word.size();

    TrieNode* p = root;
    for (int i = 0; i < wordSize; i++) {
        int ord = word[i] - 'a';
        if (p->m_next[ord] == nullptr) {
            return 0;
        }
        p = p->m_next[ord];
    }

    return p->m_ID;
}

// Ref: https://www.geeksforgeeks.org/auto-complete-feature-using-trie/
vector<string> lookUpPrefix(TrieNode* root, string prefix) {
    int prefSize = prefix.size();
    vector<string> words;

    TrieNode* p = root;
    for (int i = 0; i < prefSize; i++) {
        int ord = prefix[i] - 'a';
        if (p->m_next[ord] == nullptr) {
            return words;
        }
        p = p->m_next[ord];
    }

    dfs(p, prefix, words);

    return words;
}

void dfs(TrieNode* root, string cur, vector<string> &words) {
    if (root->m_count > 0) {
        words.emplace_back(cur);
    }

    for (int i = 0; i < 26; i++) {
        if (root->m_next[i] != nullptr) {
            char chr = i + 'a';
            dfs(root->m_next[i], cur + chr, words);
        }
    }
}

// Ref: https://gist.github.com/VinayakBorhade/2383cdb1525d3cb454938fd6fc5a2508
void Remove(TrieNode* &root, string word) {
    int wordSize = word.size();
    TrieNode* p = root;
    stack<pair<TrieNode*, int>> st;

    for (int i = 0; i < wordSize; i++) {
        int ord = word[i] - 'a';
        if (p->m_next[ord] == nullptr) {
            return;
        }
        p = p->m_next[ord];
        st.emplace(p, ord);
    }

    bool isLastChr = true;
    while (!st.empty()) {
        p = st.top().first;
        int ord = st.top().second;
        st.pop();

        if (!isLeafNode(p)) {
            if (isLastChr) { // the to-be-removed word is a prefix of other word(s)
                p->m_ID = 0;
                p->m_count--;
            }
            return;
        }
        else if (isLastChr) {
            p->m_ID = 0;
            p->m_count--;
        }
        delete p;
        st.top().first->m_next[ord] = nullptr; // p = nullptr
        isLastChr = false;
    }

    if (isLeafNode(root)) {
        delete root;
        root = nullptr;
    }
}

bool isLeafNode(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->m_next[i] != nullptr) {
            return false;
        }
    }
    return true;
}