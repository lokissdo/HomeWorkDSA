#include "LinkedListPQueue.h"
bool LLPQueue::isEmpty()
{
	return head == NULL;
}

void LLPQueue::insert(string ID, int priority)
{
	if (isEmpty()) {
		head = new LLNode{ ID,priority,NULL };
		return;
	}
	if (head->priority > priority) {
		head = new LLNode{ ID,priority,head };
		return;
	}
	LLNode* pCrawl = head->next;
	LLNode* previousLLNode = head;
	while (pCrawl && pCrawl->priority < priority) {
		previousLLNode = pCrawl;
		pCrawl = pCrawl->next;
	}
	previousLLNode->next = new LLNode{ ID,priority,pCrawl };
}

LLNode* LLPQueue::extract()
{
	if (isEmpty()) return NULL;
	LLNode* res = head;
	head = head->next;
	return res;
}

bool LLPQueue::remove(string ID)
{
	if (isEmpty()) return 0;
	if (head->ID == ID) {
		LLNode* temp = head;
		head = head->next;
		delete temp;
	}

	LLNode* pCrawl = head->next;
	LLNode* previousLLNode = head;

	while (pCrawl && pCrawl->ID != ID) {
		previousLLNode = pCrawl;
		pCrawl = pCrawl->next;
	}
	if (pCrawl == NULL) return 0;
	previousLLNode->next = pCrawl->next;
	delete pCrawl;
	return 1;
}

void LLPQueue::changePriority(string ID, int newPriority)
{
	if (remove(ID))
		insert(ID, newPriority);
}

LLPQueue::LLPQueue()
{
	head = NULL;
}

LLPQueue::~LLPQueue()
{
	LLNode* temp;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}
