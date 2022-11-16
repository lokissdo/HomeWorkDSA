#include "MLList.h"
Lref createLeader(int key, Lref next ) {
	Lref res = new Leader;
	res->next = next;
	res->count = 0;
	res->key = key;
	res->head = NULL;
	return res;
}

Tref createTrailer(Lref id, Tref next ) {
	Tref res = new Trailer;
	res->id = id;
	res->next = next;
	return res;
}

Lref addLeader(Lref& head, int key, int& leaderCounter) {
	Lref pCrawl = head;
	while (pCrawl && pCrawl->key != key) pCrawl = pCrawl->next;
	if (pCrawl == NULL) {
		head = createLeader(key, head);
		pCrawl = head;
		leaderCounter++;
	}
	return pCrawl;
}

void addRelationship(Lref& head, int first, int second, int& leaderCounter) {
	Lref firstLeader = addLeader(head, first, leaderCounter);
	Lref secondLeader = addLeader(head, second, leaderCounter);

	firstLeader->head = createTrailer(secondLeader, firstLeader->head);
	secondLeader->count++;
}

void destroyList(Lref& root)
{
	while (root) {
		Lref temp = root;
		root = root->next;
		delete[] temp;
	}
}
