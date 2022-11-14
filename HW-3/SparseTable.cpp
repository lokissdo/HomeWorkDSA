#include "SparseTable.h"

int64_t SparseTable::min(int64_t a, int64_t b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int64_t SparseTable::max(int64_t a, int64_t b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int64_t SparseTable::gcd(int64_t a, int64_t b) {
    while (b) {
        int64_t rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

SparseTable::SparseTable() {
    m_powK = 0;
    m_arrSize = 0;
}

SparseTable::SparseTable(vector<int64_t> arr, Func F, int funcType, const string FileName) {
    ofstream outp;
    outp.open(FileName, ios::out);

    m_powK = log2_fast(arr.size()) + 1;
    m_arrSize = arr.size();
    m_funcType = funcType;

    for (int i = 0; i <= m_powK; i++) {
        m_table[i].resize(m_arrSize);
    }

    for (int i = 0; i < m_arrSize; i++) {
        m_table[0][i] = arr[i];
    }

    for (int i = 1; i <= m_powK; i++) {
        for (int j = 0; j + (1 << i) - 1 < m_arrSize; j++) {
            m_table[i][j] = F(m_table[i - 1][j], m_table[i - 1][j + (1 << (i - 1))]);
        }
    }

    outp << m_powK << ' ' << m_arrSize << ' ' << m_funcType << '\n';

    for (int i = 0; i <= m_powK; i++) {
        for (int j = 0; j < m_arrSize; j++) {
            outp << m_table[i][j] << ' ';
        }
        outp << '\n';
    }

    outp.close();
}

void SparseTable::build(vector<int64_t> arr, Func F, int funcType, const string FileName) {
    ofstream outp;
    outp.open(FileName, ios::out);

    m_powK = log2_fast(arr.size()) + 1;
    m_arrSize = arr.size();
    m_funcType = funcType;

    for (int i = 0; i <= m_powK; i++) {
        m_table[i].resize(m_arrSize);
    }

    for (int i = 0; i < m_arrSize; i++) {
        m_table[0][i] = arr[i];
    }

    for (int i = 1; i <= m_powK; i++) {
        for (int j = 0; j + (1 << i) - 1 < m_arrSize; j++) {
            m_table[i][j] = F(m_table[i - 1][j], m_table[i - 1][j + (1 << (i - 1))]);
        }
    }

    outp << m_powK << ' ' << m_arrSize << ' ' << m_funcType << '\n';

    for (int i = 0; i <= m_powK; i++) {
        for (int j = 0; j < m_arrSize; j++) {
            outp << m_table[i][j] << ' ';
        }
        outp << '\n';
    }

    outp.close();
}

int64_t SparseTable::answer(int left, int right, Func F) {
    if (left > right || left < 0 || right >= m_arrSize) {
        return -INF_VAL;
    }

    int i = log2_fast(right - left + 1);

    int64_t ans = F(m_table[i][left], m_table[i][right - (1 << i) + 1]);

    return ans;
}

istream& operator >>(istream &in, SparseTable &st) {
    in >> st.m_powK >> st.m_arrSize >> st.m_funcType;

    for (int i = 0; i <= st.m_powK; i++) {
        st.m_table[i].resize(st.m_arrSize);
        
        for (int j = 0; j < st.m_arrSize; j++) {
            in >> st.m_table[i][j];
        }
    }

    return in;
}

ostream& operator <<(ostream &out, SparseTable st) {
    for (int i = 0; i <= st.m_powK; i++) {
        for (int j = 0; j < st.m_arrSize; j++) {
            out << st.m_table[i][j] << ' ';
        }
        out << '\n';
    }

    return out;
}

int log2_fast(int64_t num) {
    return num > 0 ? __builtin_clzll(1) - __builtin_clzll(num) : -1;
}