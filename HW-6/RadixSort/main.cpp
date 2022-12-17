#include "LinkedList.h"

int main() {
    ifstream inp;
    inp.open("input.txt", ios::in);
    if (!inp.good()) {
        return 0;
    }

    NRef head = nullptr;
    NRef tail = nullptr;

    int k, n, max_val = 0;
    inp >> k >> n;

    for (int i = 0; i < n; i++) {
        int x;
        inp >> x;
        addTail(head, tail, x);
        if (x > max_val) {
            max_val = x;
        }
    }

    inp.close();
    
    int d = 0;
    while (max_val > 0) {
        max_val /= 10;
        d++;
    }

    radixSort(head, tail, k, d);
    for (NRef p = head; p != nullptr;) {
        cout << p->key << ' ';
        NRef nTemp = p;
        p = p->next;
        delete nTemp;
    }
}