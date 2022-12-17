#include "RBTree.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;


Ref createNilNode()
{
	Ref nil = new RBNode;
	nil->color = BLACK;
	nil->parent = nil;
	nil->left = nil;
	nil->right = nil;
	return nil;
}

Ref nil = createNilNode();
Ref getNill()
{
	return nil;
}

Ref initRBTree()
{
	return nil;
}

bool isEmpty(Ref root)
{
	return root == nil;
}

int max(int a, int b) {
	return ((a > b) ? a : b);
}

void leftRotate(Ref& root, Ref x)
{
	Ref y = x->right;
	x->right = y->left;
	if (y->left != nil) {
		y->left->parent = x;
	}
	if (x->parent == nil)
		root = y;
	else {
		if (x->parent->left == x)
			x->parent->left = y;
		else x->parent->right = y;
	}
	y->left = x;
	y->parent = x->parent;
	x->parent = y;
}


void rightRotate(Ref& root, Ref x)
{
	Ref y = x->left;
	x->left = y->right;
	if (y->right != nil) {
		y->right->parent = x;
	}
	if (x->parent == nil)
		root = y;
	else {
		if (x->parent->left == x)
			x->parent->left = y;
		else x->parent->right = y;
	}
	y->right = x;
	y->parent = x->parent;
	x->parent = y;
}

Ref getNode(int key, int color)
{
	Ref p = new RBNode;
	p->key = key;
	p->color = color;
	p->left = p->right = p->parent = nil;
	return p;
}


void ins_leftAdjust(Ref& root, Ref& x) {

	// consider parent's sibling
	// if it's red node
	Ref u = x->parent->parent->right;
	if (u->color == RED) {
		x->parent->color = BLACK;
		u->color = BLACK;
		x->parent->parent->color = RED;
		//change x into its grandparent to continue balancing process
		x = x->parent->parent;
	}
	// if it's black node
	else {
		if (x == x->parent->right) {
			x = x->parent;
			leftRotate(root, x);
		}

		// rotate and end up balancing process
		x->parent->color = BLACK;
		x->parent->parent->color = RED;
		rightRotate(root, x->parent->parent);
	}
}


void ins_rightAdjust(Ref& root, Ref& x) {
	Ref u = x->parent->parent->left;
	if (u->color == RED) {
		x->parent->color = BLACK;
		u->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;
	}
	else {
		if (x == x->parent->left) {
			x = x->parent;
			rightRotate(root, x);
		}
		x->parent->color = BLACK;
		x->parent->parent->color = RED;
		leftRotate(root, x->parent->parent);
	}
}

void Insert(Ref& root, int key)
{
	Ref y = nil;
	Ref z = root;
	Ref x = getNode(key, RED);
	while (z != nil) {
		y = z;
		if (x->key < z->key) z = z->left;
		else if (x->key > z->key) z = z->right;
		else return;
	}
	x->parent = y;
	if (y == nil) root = x;
	else
		if (x->key < y->key) y->left = x;
		else y->right = x;
	Insertion_FixUp(root, x);
}

Ref createTree(int a[], int n)
{
	Ref pRoot = initRBTree();
	for (int i = 0; i < n; i++)
		Insert(pRoot, a[i]);
	return pRoot;
}

Ref lookUp(Ref pRoot, int key)
{
	while (pRoot != nil) {
		if (pRoot->key < key) pRoot = pRoot->right;
		else if (pRoot->key > key) pRoot = pRoot->left;
		else return pRoot;
	}
	return nil;
}

int Height(Ref pRoot)
{
	// nil node has height 1
	if (pRoot == nil) return 1;
	int leftHeight = Height(pRoot->left);
	int rightHeight = Height(pRoot->right);
	return max(leftHeight, rightHeight) + 1;
}

int BlackHeight(Ref pRoot)
{
	// nil node is a black node
	if (pRoot == nil) return 1;
	bool isBlackNode = (pRoot->color == BLACK) ? 1 : 0;
	int leftHeight = BlackHeight(pRoot->left);
	int rightHeight = BlackHeight(pRoot->right);
	return max(leftHeight, rightHeight) + isBlackNode;
}

Ref TreeSuccessor(Ref z) {
	// leftmost node of right tree
	Ref alterNode = z->right;
	while (alterNode->left != nil)
		alterNode = alterNode->left;
	return alterNode;
}



void del_leftAdjust(Ref& root, Ref& x) {
	Ref w = x->parent->right;
	// sibling's color is red
	// remain black token
	if (w->color == RED) {
		w->color = BLACK;
		x->parent->color = RED;
		leftRotate(root, x->parent);
		w = x->parent->right;
	}

	// sibling's color is black

	if ((w->right->color == BLACK) &&
		(w->left->color == BLACK)) {
		w->color = RED;
		x = x->parent; //change token to its parent
	}
	else {
		if (w->right->color == BLACK) {
			w->left->color = BLACK;
			w->color = RED;
			rightRotate(root, w);
			w = x->parent->right;
			//w = w->parent;
		}
		//if sibling's child is red, rotate and end up balance
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->right->color = BLACK;
		leftRotate(root, x->parent);
		x = root;
	}
}

void del_rightAdjust(Ref& root, Ref& x) {
	Ref w = x->parent->left;
	// sibling's color is red
	// remain black token
	if (w->color == RED) {
		w->color = BLACK;
		x->parent->color = RED;
		rightRotate(root, x->parent);
		w = x->parent->left;
	}

	// sibling's color is black

	if ((w->right->color == BLACK) &&
		(w->left->color == BLACK)) {
		w->color = RED;
		x = x->parent; //change token to its parent
	}
	else {
		if (w->left->color == BLACK) {
			w->right->color = BLACK;
			w->color = RED;
			leftRotate(root, w);
			w = x->parent->left;
			//w = w->parent;
		}
		//if sibling's child is red, rotate and end up balance
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->left->color = BLACK;
		rightRotate(root, x->parent);
		x = root;
	}
}

void Del_FixUp(Ref root, Ref x) {
	while ((x->color == BLACK) && (x != root))
		if (x == x->parent->left)
			del_leftAdjust(root, x);
		else
			del_rightAdjust(root, x);
	// if it's red-black token
	x->color = BLACK;
}

int Remove(Ref& pRoot, int key)
{
	Ref z = lookUp(pRoot, key);
	if (z == nil) return 0;
	Ref y = (z->left == nil) || (z->right == nil) ?
		z : TreeSuccessor(z);
	Ref x = (y->left == nil) ? y->right : y->left;
	x->parent = y->parent;
	if (y->parent == nil) pRoot = x;
	else
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	if (y != z) z->key = y->key;
	if (y->color == BLACK)
		Del_FixUp(pRoot, x);
	delete y;
	return 1;
}

void Insertion_FixUp(Ref& root, Ref x)
{
	while (x->parent->color == RED)
		if (x->parent == x->parent->parent->left)
			ins_leftAdjust(root, x);
		else
			ins_rightAdjust(root, x);
	root->color = BLACK;
}

void destroyTree(Ref& root)
{
	if (isEmpty(root)) return;
	stack<Ref> st;
	st.push(root);
	root = nil;
	Ref ptr;
	while (!st.empty()) {
		ptr = st.top();
		st.pop();
		if (ptr->left != nil) st.push(ptr->left);
		if (ptr->right != nil) st.push(ptr->right);
		delete ptr;
	}
}

void inOrder(Ref root)
{
	stack<Ref> s;
	Ref curr = root;

	while (curr != nil || s.empty() == false)
	{
		while (curr != nil)
		{
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();

		cout << curr->key << " ";
		curr = curr->right;

	}
}

void levelOrder(Ref pRoot)
{
		if (!pRoot) return;
		queue<Ref> qu;
		qu.push(pRoot);
		while (!qu.empty()) {
			Ref curr = qu.front();
			qu.pop();
			cout << curr->key << " ";
			if (curr->left != nil) qu.push(curr->left);
			if (curr->right != nil) qu.push(curr->right);
		}

}
