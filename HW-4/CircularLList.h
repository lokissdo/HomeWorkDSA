#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node {
	T key;
	Node* next;
	Node() {
		next = NULL;
	}
	Node(T data) {
		next = NULL;
		key = data;
	}
};

template <class T>
struct CircularLList {
	 Node<T>* last;
	 CircularLList() {
		 last = NULL;
	 }
};

