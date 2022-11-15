#include "LinkedListPQueue.h"
#include "MinHeapPQueue.h"

#include <iostream>
using namespace std;

void testLinkedListQueue() {
	LLPQueue queue;

	// Check if queue is empty
	if (queue.isEmpty())
		cout << "Queue is empty" << "\n";

	//Initialize queue
	queue.insert("a", 123);
	queue.insert("b", 56);
	queue.insert("c", 1);
	queue.insert("d", 12);
	queue.insert("e", 3);

	//get ID of extracted element 
	cout << queue.extract()->ID << "\n";

	//Change priority of element containing ID "a"
	queue.changePriority("a", 0);
	cout << queue.extract()->ID << "\n";
	cout << queue.extract()->ID << "\n";

	//Remove element containing ID "a"
	queue.remove("d");

	cout << queue.extract()->ID << "\n";

	if (queue.isEmpty())
		cout << "Queue is empty" << "\n";
}

void testMinHeapQueue() {
	MinHeapPQueue queue(300);

	if (queue.isEmpty())
		cout << "Queue is empty" << "\n";

	//Initialize queue
	queue.insert("x", 1);
	queue.insert("y", 20);
	queue.insert("z", 39);
	queue.insert("k", 5);
	queue.insert("l", 4);

	//get ID of extracted element 
	cout << queue.extract().ID << " \n";
	cout << queue.extract().ID << " \n";

	//Change priority of element containing ID "z"
	queue.changePriority("z", 1);
	cout << queue.extract().ID << " \n";

	//Remove element containing ID "k"
	queue.remove("k");

	cout << queue.extract().ID << " \n";

	if (queue.isEmpty())
		cout << "Queue is empty" << "\n";

}

//The root element has the smallest priority value.  
int main() {
	cout << "\t - Priority Queue with Singly Linked List\n";
	testLinkedListQueue();

	cout << "\n\n\t - Priority Queue with Min Heap\n";
	testMinHeapQueue();

	return 0;
}