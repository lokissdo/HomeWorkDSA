#pragma once
#define BLACK 0
#define RED 1

typedef struct RBNode* Ref;
struct RBNode {
	int key;
	bool color; //Black = 0
	RBNode* parent;
	RBNode* left;
	RBNode* right;
};

Ref getNill();
Ref initRBTree();
bool isEmpty(Ref root);
void leftRotate(Ref& root, Ref x); 
void rightRotate(Ref& root, Ref x);
Ref getNode(int key, int color);
void Insertion_FixUp(Ref& root, Ref x);
void Del_FixUp(Ref root, Ref x);
void destroyTree(Ref& root);

void Insert(Ref& root, int x);
Ref createTree(int a[], int n);
Ref lookUp(Ref pRoot, int key);
int Height(Ref pRoot);
int BlackHeight(Ref pRoot);
int Remove(Ref& pRoot, int key);

//traversal
void inOrder(Ref root);
void levelOrder(Ref pRoot);

