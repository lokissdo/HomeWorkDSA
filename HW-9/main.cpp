#include "Process.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << "Invalid command line argument!\n";
        return 0;
    }

    if (strcmp(argv[1], "-c") == 0) { // compress
        string str(argv[2]);
        Process::Compress(str);
    }
    else if (strcmp(argv[1], "-e") == 0) { // expand
        vector<int> seq;
        for (int i = 2; i < argc; i++) {
            int val = atoi(argv[i]);
            seq.emplace_back(val);
        }
        Process::Expand(seq);
    }
}