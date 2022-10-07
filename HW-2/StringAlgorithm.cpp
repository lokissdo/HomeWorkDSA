#include "StringAlgorithm.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#define SIZE_OF_CHAR 256
using namespace std;

int KMP(string source, string pattern) {
	int lpattern = pattern.length(), lsource = source.length();
	int* kmp = new int[lpattern] {0};

	int count = 0;

	//initialize frequency of substring table
	for (int i = 1; i < lpattern; i++) {
		kmp[i] = 0;
		if (pattern[i] == pattern[kmp[i - 1]]) kmp[i] = kmp[i - 1] + 1;
	}

	//process
	int i = 0, j = 0;
	while (i < lsource) {
		if (source[i] == pattern[j]) {
			if (j == lpattern - 1) {
				++count;
				j = kmp[j];
			}
			else  j++;
			i++;
		}
		else {
			if (j == 0)
				i++;
			else j = kmp[j - 1];
		}
	}

	
	delete[]kmp;
	return count;
}

int BruteForce(string source, string pattern) {

	int lenS = source.length();
	int lenP = pattern.length();
	int count = 0;

	//process
	for (int i = 0; i <= lenS - lenP; ++i) {
		bool check = true;
		for (int j = 0; j < lenP; ++j) {
			if (source[i + j] != pattern[j]) {
				check = false;
				break;
			}
		}
		if (check) ++count;
	}

	return count;

}

int BoyerMoore(string source, string pattern)
{
	int lenS = source.length();
	int lenP = pattern.length();
	int bm [SIZE_OF_CHAR];
	int count = 0;

	//initialize position table of chars
	for (int i = 0; i < SIZE_OF_CHAR; ++i)
			bm[i] = -1;
	for (int i = 0; i < lenP; ++i)
		bm[pattern[i]] = i;

	//process
	int i = 0;
	while (i + lenP <= lenS) {
		int j = lenP - 1;
		while (j>=0&&source[i + j] == pattern[j]) j--;
		if (j < 0) {
			count++;
			if (i + lenP > lenS - 1) break;
			i +=  lenP - bm[source[i + lenP]];
		}
		else i += max(1, j - bm[source[i + j]]);
	}

	return count;

}

int RabinKarp(string source, string pattern)
{
	int lenS = source.length();
	int lenP = pattern.length();
	int count = 0;
	long long rkSource = 0;
	long long rkPattern = 0;
	long long mod = 1e15+7;

	//initialize values of source substring and pattern
	for (int i = lenP-1; i >=0 ; --i) {
		rkSource = (rkSource * SIZE_OF_CHAR + source[i])% mod;
		rkPattern = (rkPattern * SIZE_OF_CHAR + pattern[i])% mod;
	}

	//process
	int i = lenP - 1;
	while (i < lenS) {
		if (i != lenP - 1)
			rkSource = (rkSource / SIZE_OF_CHAR + source[i]*(long long)pow(SIZE_OF_CHAR,lenP-1)) % mod;
		if (rkPattern == rkSource) {
			++count;
			for(int j=0;j<lenP;++j)
				if (pattern[lenP - 1 - j] != source[i - j]) {
					--count;
					break;
				}
		}
		i++;
	}
	return count;
}
