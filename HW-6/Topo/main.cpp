#include "MLList.h"
#include "Input.h"
#include <iostream>

using namespace std;

int main() {

	Lref root = NULL;
	int leaderCounter = 0;
	vector<pair<int, int>> data = readDataFromFile("input.txt");

	//initialize multiple linked list
	for (auto item : data)
		addRelationship(root, item.first, item.second, leaderCounter);

	Lref sortedListHead = NULL;
	Lref sortedListTail = NULL;
	Lref zeroCountLeader = NULL;

	//find elements having count = 0
	while (root) {
		Lref temp = root->next;
		if (root->count == 0) {
			root->next = zeroCountLeader;
			zeroCountLeader = root;

		}
		root = temp;
	}

	// traverse objects not trailer of any leader ( count  = 0)
	while (zeroCountLeader) {
		Lref temp = zeroCountLeader->next;
		Tref pCrawl = zeroCountLeader->head;

		//insert leader into result list
		if (!sortedListHead)  sortedListHead = sortedListTail = zeroCountLeader;
		else {
			sortedListTail->next = zeroCountLeader;
			sortedListTail = sortedListTail->next;
		}
		leaderCounter--;

		// update count attribute for each trailer
		while (pCrawl) {
			pCrawl->id->count--;

			// if trailer's count = 0, add the node into next traversions. 
			if (pCrawl->id->count == 0) {
				pCrawl->id->next = temp;
				temp = pCrawl->id;

			}
			pCrawl = pCrawl->next;
		}
		zeroCountLeader = temp;
	}

	sortedListTail->next = NULL;
	if (leaderCounter != 0)
		cout << "Topo order doesn't exist.";
	else 
		while (sortedListHead) {
			cout << sortedListHead->key << " ";
			sortedListHead = sortedListHead->next;
		}
	//release memory
	destroyList(sortedListHead);
	return 0;
}