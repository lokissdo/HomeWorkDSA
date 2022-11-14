#include "Process.h"

void Process::make(const char* name, const char* tableType, vector<int64_t> arr) {
    // Assume that at first there is no sparse table was stored.

    string n_name = string(name);
    string FileName = PREF_FILE_NAME + n_name + ".txt";
    int cntFile = 0;
    
    if (filesystem::exists("countFile.txt") == 0) {
        ofstream outp;
        outp.open("countFile.txt", ios::out);
        outp << cntFile;
        outp.close();
    }
    else {
        ifstream inp;
        inp.open("countFile.txt", ios::in);
        inp >> cntFile;
        inp.close();
    }

    cntFile++;
    if (filesystem::exists(FileName)) {
        cntFile--;
    }

    if (cntFile > 5) {
        cerr << "Maximum number of files exceeded!\n";
        return;
    }
    else {
        ofstream outp;
        outp.open("countFile.txt", ios::out);
        outp << cntFile;
        outp.close();
    }

    string n_tableType = string(tableType);

    int funcType = SparseTable::FunctionType::MinFunc;

    if (n_tableType.compare("MAX") == 0) {
        funcType = SparseTable::FunctionType::MaxFunc;
    }
    else if (n_tableType.compare("GCD") == 0) {
        funcType = SparseTable::FunctionType::GCDFunc;
    }

    Func f;
    switch (funcType) {
        case SparseTable::FunctionType::MinFunc: {
            f = SparseTable::min;
            break;
        }
        case SparseTable::FunctionType::MaxFunc: {
            f = SparseTable::max;
            break;
        }
        default: {
            f = SparseTable::gcd;
        }
    }

    SparseTable sTable;

    sTable.build(arr, f, funcType, FileName);

    cout << tableType << "-Sparse Table " << name << ":\n" << sTable << '\n';
}

int64_t Process::query(const char* name, int left, int right) {
    string FileName = PREF_FILE_NAME + name + ".txt";

    ifstream inp;
    inp.open(FileName, ios::in);

    if (!inp.good()) {
        cerr << "Invalid data file!\n";
        inp.close();
        return -INF_VAL;
    }

    SparseTable sTable;
    inp >> sTable;

    inp.close();

    Func f;
    switch (sTable.m_funcType) {
        case SparseTable::FunctionType::MinFunc: {
            f = SparseTable::min;
            break;
        }
        case SparseTable::FunctionType::MaxFunc: {
            f = SparseTable::max;
            break;
        }
        default: {
            f = SparseTable::gcd;
        }
    }

    return sTable.answer(left, right, f);
}