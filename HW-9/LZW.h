#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
using namespace std;

class LZW {
public:
    static pair<vector<int>, int> Compress(string str); // compression result & compression ratio
    static pair<string, int> Decompress(vector<int> seq);
};

double compression_ratio(int N, int n);

int log2_fast(int64_t num);