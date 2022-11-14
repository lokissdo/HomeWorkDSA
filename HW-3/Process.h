#pragma once
#include "SparseTable.h"

const string PREF_FILE_NAME = "sparseTable";

class Process {
public:
    static void make(const char* name, const char* tableType, vector<int64_t> arr);

    static int64_t query(const char* name, int left, int right);
};