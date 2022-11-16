#include "Input.h"
#include <fstream>
#include <iostream>
vector<pair<int, int>> readDataFromFile(string fileName)
{
	//open file
	fstream input(fileName, ios::in);
	if (!input.is_open()) {
		cerr << "Can not open file!.";
		exit(1);
	}

	//read objects by pair
	vector<pair<int, int>> res;
	string buffer;
	while (!input.eof()) {
		getline(input, buffer, ')');
		if (buffer=="") break;
		int commaPos = buffer.find(",", 1);
		int first = stoi(buffer.substr(1, commaPos - 1));
		int second = stoi(buffer.substr(commaPos + 1));
		res.push_back({first,second });
	}

	return res;
}
