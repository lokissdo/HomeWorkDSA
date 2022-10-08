#include "helper.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "Command line arguments error!\n";
        exit(EXIT_FAILURE);
    }

    int numToFind = atoi(argv[1]), arrSize = argc - 2;
    int *arr = new int[arrSize];

    for (int i = 2; i < argc; i++) {
        arr[i-2] = atoi(argv[i]);
    }
    pair<int, int> ans = InterpolationSearch(arr, arrSize, numToFind);

    if (ans.first > 0) {
        cout << ans.first << " - " << ans.second << '\n';
    } else {
        cout << -1 << '\n';
    }

    delete []arr;

    return 0;
}