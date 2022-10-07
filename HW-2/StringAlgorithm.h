#pragma once
#include <string>
using namespace std;
int KMP(string source, string pattern); 
int BruteForce(string source, string pattern); 
int BoyerMoore(string source, string pattern);
int RabinKarp(string source, string pattern);