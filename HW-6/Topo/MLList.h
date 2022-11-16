#pragma once
#include<iostream>
typedef struct Trailer* Tref;
typedef struct Leader* Lref;
struct Trailer
{
	Lref id;
	Tref next;

};
struct Leader {
	int key;
	int count;
	Tref head;
	Lref next;
	~Leader() {
		while (head) {
			Tref temp = head;
			head = head->next;
			delete[] temp;
		}
	}
};
Lref createLeader(int key, Lref next = NULL);
Tref createTrailer(Lref id, Tref next = NULL);
Lref addLeader(Lref& head, int key, int& leaderCounter);
void addRelationship(Lref& head, int first, int second, int& leaderCounter);
void destroyList(Lref& root);
