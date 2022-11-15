#include "MinHeapPQueue.h"
#include <iostream>
MinHeapPQueue::MinHeapPQueue(int maxSize)
{
	m_data = new HeapNode[maxSize+1];
	m_maxSize = maxSize;
	m_currentSize = 0;
}

MinHeapPQueue::~MinHeapPQueue()
{
	delete[] m_data;
}

void swap(HeapNode& first, HeapNode& second) {
	HeapNode temp = first;
	first = second;
	second = temp;
}
void MinHeapPQueue::siftUp(int index)
{
	while (index > 1) {
		int parentIndex = index / 2;
		int swapIndex = 2 * parentIndex;
		if (swapIndex + 1 <= m_currentSize)
			if (m_data[swapIndex + 1].priority < m_data[swapIndex].priority) swapIndex++;
		if (m_data[swapIndex].priority >= m_data[parentIndex].priority) break;
		swap(m_data[swapIndex], m_data[parentIndex]);
		index = parentIndex;
	}
}

void MinHeapPQueue::siftDown(int index)
{
	while (2 * index <= m_currentSize) {
		int swapIndex = 2 * index;
		if (swapIndex + 1 <= m_currentSize)
			if (m_data[swapIndex + 1].priority < m_data[swapIndex].priority) swapIndex++;
		if (m_data[swapIndex].priority >= m_data[index].priority) break;
		swap(m_data[swapIndex], m_data[index]);
		index = swapIndex;
	}
}

bool MinHeapPQueue::isEmpty()
{
	return m_currentSize == 0;
}

void MinHeapPQueue::insert(string ID, int priority)
{
	if (m_currentSize == m_maxSize) {
		cerr << "\nOverflow: Can not insert element.";
		return;
	}
	++m_currentSize;
	m_data[m_currentSize] = HeapNode{ ID,priority };
	siftUp(m_currentSize);
}

HeapNode MinHeapPQueue::extract()
{
	HeapNode res = m_data[1];
	swap(m_data[1], m_data[m_currentSize--]);
	siftDown(1);
	return res;
}

void MinHeapPQueue::remove(string ID)
{
	for(int i=1;i<=m_currentSize;i++){
		if (m_data[i].ID == ID) {
			int removedPriority = m_data[i].priority;
			m_data[i] = m_data[m_currentSize--];
			if (m_data[i].priority > removedPriority)
				siftDown(i);
			else if(m_data[i].priority < removedPriority)
				siftUp(i);
			break;
		}
	}
}

void MinHeapPQueue::changePriority(string ID, int newPriority)
{
	for (int i = 1; i <= m_currentSize; i++) {
		if (m_data[i].ID == ID) {
			int changedPriority = m_data[i].priority;
			m_data[i].priority = newPriority;
			if (m_data[i].priority > changedPriority)
				siftDown(i);
			else if (m_data[i].priority < changedPriority)
				siftUp(i);
			break;
		}
	}
}
