#pragma once
#include "LZW.h"

class Process {
public:
    static void Compress(string str);
    static void Expand(vector<int> seq);
};