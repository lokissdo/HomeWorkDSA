#include "helper.h"

pair<int, int> InterpolationSearch(int *arr, int arrSize, int num) {
    int left = 0, right = arrSize - 1, mid;
    int cnt_loops = 0;

    while (left <= right && arr[left] <= num && num <= arr[right]) {
        ++cnt_loops;

        mid = left + (num - arr[left]) * (right - left) / (arr[right] - arr[left]);

        if (arr[mid] == num) {
            return make_pair(mid + 1, cnt_loops);
        }

        if (arr[mid] > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return make_pair(-1, cnt_loops);
}