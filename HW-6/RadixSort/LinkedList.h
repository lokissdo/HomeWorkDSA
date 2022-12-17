#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
#include <chrono>
#include <random>
using namespace std;

// Instead of using "typedef"
using NRef = struct Node*;
using BRef = struct Bucket*;

struct Node {
    int key;
    NRef next;
};

struct Bucket {
    int key;
    NRef head;
    NRef tail;
    BRef next;
};

NRef getNode(int k);
void addTail(NRef &head, NRef &tail, int k);

BRef getBucket(int k);
BRef Insert(BRef head, int k);

void radixSort(NRef &head, NRef &tail, int k, int d);