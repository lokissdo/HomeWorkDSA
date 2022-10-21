#pragma once
#include "CircularLList.h"
#include <iostream>
using namespace std;

template <class T>
bool isEmpty(CircularLList<T> l);

template <class T>
Node<T>* makeNode(T data, Node<T>*);

template <class T>
void addHead(CircularLList<T>& l, T data);

template <class T>
void addTail(CircularLList<T>& l, T data);

template <class T>
void removeHead(CircularLList<T>& l);

template <class T>
void removeTail(CircularLList<T>& l);

template <class T>
void addAfter(CircularLList<T>& l, T val, T key);

template <class T>
void removeAfter(CircularLList<T>& l, T val);

template <class T>
void printList(const CircularLList<T>& l);

template<class T>
inline bool isEmpty(CircularLList<T> l)
{
	return !l.last;
}

template<class T>
inline Node<T>* makeNode(T data, Node<T>* next)
{
	Node<T>* res = new Node<T>(data);
	res->next = next;
	return res;
}

template<class T>
inline void addHead(CircularLList<T>& l, T data)
{
	if (isEmpty(l)) {
		l.last = makeNode(data, l.last);
		l.last->next = l.last;
	}
	else l.last->next = makeNode(data, l.last->next);
}

template<class T>
inline void addTail(CircularLList<T>& l, T data)
{
	if (isEmpty(l)) {
		l.last = makeNode(data, l.last);
		l.last->next = l.last;
	}
	else {
		l.last->next = makeNode(data, l.last->next);
		l.last = l.last->next;
	}
}

template<class T>
inline void removeHead(CircularLList<T>& l)
{
	if (isEmpty(l)) return;
	if (l.last == l.last->next) {
		delete l.last;
		l.last = NULL;
		return;
	}
	Node<T>* tmp = l.last->next;
	l.last->next = tmp->next;
	delete tmp;
}

template<class T>
inline void removeTail(CircularLList<T>& l)
{
	if (isEmpty(l)) return;
	if (l.last == l.last->next) {
		delete l.last;
		l.last = NULL;
		return;
	}
	Node<T>* tmp = l.last->next;
	while (tmp->next != l.last) tmp = tmp->next;
	tmp->next = l.last->next;
	delete l.last;
	l.last = tmp;
}

template<class T>
inline void addAfter(CircularLList<T>& l, T val, T key)
{
	if (isEmpty(l)) return;
	Node<T>* pCrawl = l.last->next;
	if (val == l.last->key) {
		addTail(l, key);
		cout << "\nTail la: " << l.last->key << "\n";
		return;
	}
	while (pCrawl != l.last && pCrawl->key != val) 
		pCrawl = pCrawl->next;
	if (pCrawl->key == val)
		pCrawl->next = makeNode(key, pCrawl->next);
}

template<class T>
inline void removeAfter(CircularLList<T>& l, T val)
{
	if (isEmpty(l)) return;
	Node<T>* pCrawl = l.last->next;
	while (pCrawl != l.last && pCrawl->key != val) 
		pCrawl = pCrawl->next;
	if (pCrawl->key == val) {
		if (pCrawl->next == l.last) {
			removeTail(l);
			return;
		}
		Node<T>* tmp = pCrawl->next;
		pCrawl->next = tmp->next;
		delete tmp;
	}

}

template<class T>
inline void printList(const CircularLList<T>& l)
{
	Node<T>* p = l.last->next;
	cout << p->key << " ";
	p = p->next;

	while (p != l.last->next) {
		cout << p->key << " ";
		p = p->next;
	}
}
