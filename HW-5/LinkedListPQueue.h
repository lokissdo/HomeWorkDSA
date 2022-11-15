#pragma once
#include <string>
using namespace std;

struct LLNode {
	string ID;
	int priority;
	LLNode* next;
};

class LLPQueue {
private:
	LLNode* head;
public:
	LLPQueue();
	~LLPQueue();

	bool isEmpty();
	void insert(string ID, int priority);
	LLNode* extract();
	bool remove(string ID);
	void changePriority(string ID, int newPriority);

};