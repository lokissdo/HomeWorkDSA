#include <iostream>
#include <fstream>
#include <string>
#include <time.h> 
#include <chrono>

#include "StringAlgorithm.h"
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {
	if (argc != 4) {
		cerr << "Error: Invalid Command Line!";
		exit(1);
	}
	ifstream input(argv[1]);
	if (!input.is_open()) {
		cerr << "Error: File doesn't exist!";
		exit(1);
	}

	string source;
	string pattern(argv[2]);
	string algthm(argv[3]);
	getline(input, source);

	auto start = high_resolution_clock::now();

	int count;
	if (algthm == "BM") 
		count= BoyerMoore(source, pattern);
	else if(algthm=="BF")
		count = BruteForce(source, pattern);
	else if (algthm == "RK")
		count = RabinKarp(source, pattern);	
	else if (algthm == "KMP")
		count = KMP(source, pattern);
	else {
		cerr << "Error: File doesn't exist!";
		exit(1);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << count << "-" << (float)duration.count()/1000;

	return 0;
}