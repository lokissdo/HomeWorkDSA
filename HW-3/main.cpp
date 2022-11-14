#include "SparseTable.h"
#include "Process.h"

int main(int argc, char** argv) {
    if (argc < 5) {
        cerr << "Command line argument error!\n";;
        return 0;
    }

    if (strcmp(argv[1], "make") == 0) {
        vector<int64_t> inpArr;
        for (int i = 4; i < argc; i++) {
            int tempVal = atoi(argv[i]);
            inpArr.push_back(tempVal);
        }

        Process::make(argv[2], argv[3], inpArr);
    }
    else if (strcmp(argv[1], "query") == 0) {
        if (argc != 5) {
            cerr << "Command line argument error!\n";
            return 0;
        }

        int64_t ans = Process::query(argv[2], atoi(argv[3]), atoi(argv[4]));

        cout << ans << '\n';
    }
}