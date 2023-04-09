#include <iostream>
#include "Stack_Class.h"


int main() {

	Stack_Class s;
	Stack_Type st;
	
	
	s.Create(&st);
	s.Push(&st,1); s.Stack_View(&st);
	s.Push(&st,2); s.Stack_View(&st);
	s.Push(&st,3); s.Stack_View(&st);
	s.Push(&st,4); s.Stack_View(&st);
	s.Push(&st,5); s.Stack_View(&st);
	s.Pop(&st); s.Stack_View(&st);
	s.Pop(&st); s.Stack_View(&st);
	printf("Stack Size : %d\n", s.GetSize(&st));
	printf("Stack Top Data : %d\n", s.GetTop(&st));
	s.Destroy(&st); s.Stack_View(&st);

	return 0;
}