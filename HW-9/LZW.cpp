#include "LZW.h"

pair<vector<int>, int> LZW::Compress(string str) {
    vector<int> compressedSeq;
    vector<string> binaryCompressedSeq;

    map<string, int> dict; // a dictionary
    for (int i = 1; i < 256; i++) {
        string s;
        s = char(i);
        dict.emplace(s, i); // consider each character as a word and add it to the dictionary
    }
    
    string s;
    int curCode = 256;
    for (char c : str) {
        if (dict.count(s + c)) { // check if s + c exists in the dictionary or not
            s += c;
        }
        else {
            dict.emplace(s + c, curCode++); // if not then add it to the dictionary
            compressedSeq.emplace_back(dict[s]);
            s = c;
        }
    }
    compressedSeq.emplace_back(dict[s]);
    
    int max_val = 0;
    for (int val : compressedSeq) {
        if (val > max_val) {
            max_val = val;
        }
    }
    
    return make_pair(compressedSeq, log2_fast(max_val) + 1);
}

pair<string, int> LZW::Decompress(vector<int> seq) {
    map<int, string> dict;
    for (int i = 1; i < 256; i++) {
        string s;
        s = char(i);
        dict.emplace(i, s);
    }
    
    string s = dict[seq[0]];
    int max_val = seq[0];

    string decompressedString = s;
    int code = 256;
    for (int i = 1; i < (int)seq.size(); i++) {
        string entry = dict.count(seq[i]) ? dict[seq[i]] : "";
        decompressedString += entry;
        dict.emplace(code++, s + entry.front());
        s = entry;
        if (seq[i] > max_val) {
            max_val = seq[i];
        }
    }
    
    return make_pair(decompressedString, log2_fast(max_val) + 1);
}

double compression_ratio(int N, int n) {
    return (1.0 * (N - n) / N) * 100.0;
}

int log2_fast(int64_t num) {
    return num > 0 ? __builtin_clzll(1) - __builtin_clzll(num) : -1;
}