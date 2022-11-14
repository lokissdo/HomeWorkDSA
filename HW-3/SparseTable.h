#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <filesystem>
using namespace std;

const int K = 25;
const int MAX_SIZE = 1e6;
const int64_t INF_VAL = 1e18;

typedef int64_t (*Func)(int64_t, int64_t);

class SparseTable {
private:
    int m_powK; // m_powK should be <= 25
    int m_arrSize;

    vector<int64_t> m_table[K + 1];
public:
    int m_funcType;

    enum FunctionType {
        MinFunc,
        MaxFunc,
        GCDFunc
    };

    static int64_t min(int64_t a, int64_t b);
    static int64_t max(int64_t a, int64_t b);
    static int64_t gcd(int64_t a, int64_t b);

    SparseTable();
    SparseTable(vector<int64_t> arr, Func F, int funcType, const string FileName);

    void build(vector<int64_t> arr, Func F, int funcType, const string FileName);

    int64_t answer(int left, int right, Func F);

    friend istream& operator >>(istream &in, SparseTable &st);
    friend ostream& operator <<(ostream &out, SparseTable st);
};

int log2_fast(int64_t num);