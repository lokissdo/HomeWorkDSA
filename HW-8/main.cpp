#include <iostream>
#include "RBTree.h"
using namespace std;

int main() {
	int a[] = { 5,-5,50,15,3,9,8,80 };
	Ref root = createTree(a, sizeof(a) / sizeof(int));
	Ref nil = getNill();
	// trung thu tu
	inOrder(root);
	cout << '\n';

	Insert(root, -8);
	Insert(root, 18);
	Insert(root, 90);

	// duyet theo muc
	levelOrder(root);
	cout << '\n';

	int key = 50;
	if (lookUp(root, key) != nil)
		cout << "Ton tai node co gia tri la " << key;
	else cout << "Khong ton tai node co gia tri la " << key;
	cout << '\n';

	cout << "Chieu cao cua cay luc nay la: " << Height(root) << '\n';
	cout << "Chieu cao den cua cay luc nay la: " << BlackHeight(root) << '\n';

	key = 50;
	if (Remove(root, key)) {
		cout << "Da xoa thanh cong node co gia tri " << key;
		cout << "\nCay sau khi xoa la: ";
		inOrder(root);
	}
	else cout << "Khong ton tai node co gia tri la " << key;
	cout << '\n';

	

	//release memory
	destroyTree(root);
	delete nil;
}