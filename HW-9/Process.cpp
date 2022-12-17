#include "Process.h"

void Process::Compress(string str) {
    auto compression = LZW::Compress(str);
    vector<string> binSeq;

    for (int val : compression.first) {
        cout << val << ' ';
        bitset<64> b(val); // quick convert to binary form
        string s = b.to_string();
        s.erase(0, 64 - compression.second);
        binSeq.emplace_back(s);
    }

    cout << '\n';

    for (string val : binSeq) {
        cout << val << ' ';
    }

    cout << '\n';

    cout << compression_ratio(str.size() * sizeof(char) * 8, compression.first.size() * compression.second);
}

void Process::Expand(vector<int> seq) {
    auto decompression = LZW::Decompress(seq);

    cout << decompression.first << '\n';

    int sz = decompression.first.size();
    cout << compression_ratio(sz * sizeof(char) * 8, seq.size() * decompression.second);
}