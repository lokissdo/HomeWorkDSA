#include "Trie.h"

int main() {
    TrieNode* r;
    cout << "Create a trie from \"HW7-dic.txt\" file.\n\n";
    createTrie(r, "HW7-dic.txt");

    Remove(r, "abort");

    vector<string> words = lookUpPrefix(r, "abort");

    cout << "All words with prefix \"abort\" are: \n";
    for (string str : words) {
        cout << str << '\n';
    }
}