#pragma once
#include <string>
using namespace std;

struct HeapNode {
	string ID;
	int priority;
};

class MinHeapPQueue {
private:
	HeapNode* m_data;
	int m_currentSize;
	int m_maxSize;
public:
	MinHeapPQueue(int maxSize);
	~MinHeapPQueue();

	void siftUp(int index);
	void siftDown(int index);
	bool isEmpty();
	void insert(string ID, int priority);
	HeapNode extract();
	void remove(string ID);
	void changePriority(string ID, int newPriority);

};