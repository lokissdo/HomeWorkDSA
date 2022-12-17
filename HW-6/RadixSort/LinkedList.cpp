#include "LinkedList.h"

NRef getNode(int k) {
    NRef node = new Node;
    node->key = k;
    node->next = nullptr;

    return node;
}

void addTail(NRef &head, NRef &tail, int k) {
    NRef p = getNode(k);

    if (head == nullptr) {
        head = p;
        tail = p;
        return;
    }

    tail->next = p;
    tail = p;
}

BRef getBucket(int k) {
    BRef bucket = new Bucket;
    bucket->key = k;
    bucket->head = nullptr;
    bucket->tail = nullptr;
    bucket->next = nullptr;

    return bucket;
}

// https://youtu.be/UnX_T9f0MvE
// From 2:16:00 to 2:27:00
BRef Insert(BRef head, int k) {
    // search and add
    BRef p2 = head;
    BRef p1 = p2->next;

    while (p1 != nullptr && p1->key < k) {
        p2 = p1;
        p1 = p1->next;
    }

    // if the bucket exists then no insertion needed
    if (p1 != nullptr && p1->key == k) {
        return p1;
    }

    BRef p = getBucket(k);
    p2->next = p;
    p->next = p1;
    
    return p;
}

void radixSort(NRef &head, NRef &tail, int k, int d) {
    int digCount = 0, pow10 = 1, digSize = 1;
    for (int i = 0; i < k; i++) {
        digSize *= 10;
    }
    
    while (digCount < d) {
        BRef bHead = getBucket(-1); // initially, bHead shouldn't be nullptr but a dummy head instead
        for (NRef p = head; p != nullptr;) {
            int dig = (p->key / pow10) % digSize; // A "digit" here can contain more than one normal digit (0-9)

            BRef b = Insert(bHead, dig); // buckets are stored increasingly
            addTail(b->head, b->tail, p->key); // add current element to this bucket
            
            NRef nTemp = p;
            p = p->next;
            delete nTemp;
        }
        head = nullptr;
        tail = nullptr;

        BRef bTemp = bHead;
        bHead = bHead->next;
        delete bTemp;

        while (bHead != nullptr) {
            for (NRef p = bHead->head; p != nullptr; p = p->next) {
                addTail(head, tail, p->key); // return elements from each bucket to the original list
            }

            bTemp = bHead;
            bHead = bHead->next;
            delete bTemp;
        }

        digCount += k;
        pow10 *= digSize;
    }
}