#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "Command line arguments error!\n";
        exit(EXIT_FAILURE);
    }

    int k = atoi(argv[1]), sz = argc - 2, cnt_loops = 0, pos = -1;
    int *arr = new int[sz];

    for (int i = 2; i < argc; i++) {
        arr[i-2] = atoi(argv[i]);
    }

    // for (int i = 0; i < sz; i++) cout << arr[i] << " \n"[i == sz - 1];
    // Assume that the array is sorted.
    int l = 0, r = sz - 1 , x;

    while (l <= r && arr[l] <= k && k <= arr[r]) {
        cnt_loops++;
        x = l + (k - arr[l]) * (r - l) / (arr[r] - arr[l]);
        if (arr[x] == k) {
            pos = x;
            break;
        }
        if (arr[x] > k) {
            r = x - 1;
        }
        else {
            l = x + 1;
        }
    }
    if (pos == -1) {
        cout << -1;
    }
    else {
        cout << pos + 1 << " - " << cnt_loops;
    }
    delete []arr;
}