#include <iostream>
#include <string.h>
using namespace std;
#define Maxnode 100

typedef struct {
	char name[10];
	int lchild;
	int rchild;
}node;
typedef node Treetype[Maxnode];
Treetype tree;
int cnt = 0;
void Create() {
	strcpy_s(tree[0].name ,"Park");
	tree[0].lchild = 1;
	tree[0].rchild = 2;
}

int main() {
	
	Create();
	strcpy_s(tree[1].name, "Kim");
	tree[1].lchild = -1;
	tree[1].rchild = 3;

	strcpy_s(tree[2].name, "Seo");
	tree[2].lchild = -1;
	tree[2].rchild = 4;

	strcpy_s(tree[3].name, "Lee");
	tree[3].lchild = -1;
	tree[3].rchild = -1;

	strcpy_s(tree[4].name, "Cho");
	tree[4].lchild = -1;
	tree[4].rchild = -1;

	//Lee 삭제
	//tree[1].rchild = -1;

	//Kim 삭제
	strcpy_s(tree[1].name, tree[3].name);
	tree[1].rchild = -1;
	strcpy_s(tree[3].name, "Unused");
	return 0;
}