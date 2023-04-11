#include "Stack_Class.h"

void Stack_Class::Create(Stack_Type* sptr) {
	sptr->top = -1; 
}
bool Stack_Class::IsEmpty(Stack_Type* sptr) {
	return (sptr->top == -1);
}
bool Stack_Class::IsFull(Stack_Type* sptr) {
	return (sptr->top == max - 1);
}
void Stack_Class::Push(Stack_Type* sptr,int data) {
	if (IsFull(sptr))
		cout << "Stack Full" << endl;
	else
		sptr->data[++sptr->top] = data;
}
void Stack_Class::Pop(Stack_Type* sptr) {
	if (IsEmpty(sptr))
		cout << "Stack Empty" << endl;
	else {
		cout << "Del :";
		cout << sptr->data[sptr->top] << endl;
		sptr->data[sptr->top] = NULL;
		sptr->top--;
	}
}
int Stack_Class::GetSize(Stack_Type* sptr) {
	return sptr->top + 1;
}
int Stack_Class::GetTop(Stack_Type* sptr) {
	return sptr->data[sptr->top];
}
void Stack_Class::Destroy(Stack_Type* sptr) {
	if (IsEmpty(sptr))
		cout << "Stack Empty" << endl;
	else {
		for (int i = sptr->top; i > -1; i--) {
			sptr->data[i] = NULL;
			sptr->top--;
		}
		cout << "Stack Destroy";
	}
}
void Stack_Class::Stack_View(Stack_Type* sptr) {
	if (IsEmpty(sptr))
		cout << "Stack Empty" << endl;
	else {
		cout << "Data in Stack :";
		for (int i = 0; i <= sptr->top; i++)
			cout << sptr->data[i]<<" ";
		cout << endl;
	}
}