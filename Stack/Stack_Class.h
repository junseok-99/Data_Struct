#include <iostream>
using namespace std;
#define max 10

typedef struct Stack_Type{
	int top;
	int data[max];
}Stack_Type;


class Stack_Class {
private:
	
public:
	void Create(Stack_Type* sptr);
	void Push(Stack_Type* sptr,int data);
	void Pop(Stack_Type* sptr);
	bool IsEmpty(Stack_Type* sptr);
	bool IsFull(Stack_Type* sptr);
	int GetSize(Stack_Type* sptr);
	int GetTop(Stack_Type* sptr);
	void Destroy(Stack_Type* sptr);
	void Stack_View(Stack_Type* sptr);
};
