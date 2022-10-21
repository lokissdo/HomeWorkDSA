#include <iostream>
#include "CircularLList.h"
#include "Function.h"
using namespace std;

int main() {
	CircularLList<int> cl;
	addHead(cl, 1);
	addHead(cl, 2);
	addHead(cl, 3);
	addHead(cl, 4);
	addTail(cl, 5);
	addTail(cl,-1);
	addHead(cl, 10);

	cout << "\n\tDanh sach duoc khoi tao la: \n\t";
	printList(cl);

	cout << "\n\tDanh sach sau khi them dau la: \n\t";
	addHead(cl, 111);
	printList(cl);

	cout << "\n\tDanh sach sau khi them cuoi la: \n\t";
	addTail(cl, 99);
	printList(cl);

	cout << "\n\tDanh sach sau khi xoa dau la: \n\t";
	removeHead(cl);
	printList(cl);

	cout << "\n\tDanh sach sau khi xoa cuoi la: \n\t";
	removeTail(cl);
	printList(cl);

	cout << "\n\tDanh sach sau khi them phan tu sau 1 la: \n\t";
	addAfter(cl, 1,8);
	printList(cl);

	cout << "\n\tDanh sach sau khi xoa phan tu sau 1 la: \n\t";
	removeAfter(cl, 1);
	printList(cl);
	return 0;
}