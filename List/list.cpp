#include "list_clss.h"

nptr List::Create(int max,nptr p) {
	listmax = max;
	listcount = 0;
	p = (node*)malloc(sizeof(node));
	return p;
}
bool List::IsEmpty() {
	if (listcount == 0)
		return true;
	else
		return false;
}
bool List::IsFull() {
	if (listcount >= listmax)
		return true;
	else
		return false;
}
nptr List::Insert(int position, int data, nptr p) {
	nptr tmp = NULL, q = NULL;
	if (position > listmax)
		printf("포지션 리스트길이 초과.\n");
	if (IsFull())
		printf("리스트가 가득참.\n");
	else if ((position > listcount + 1) || position < 1)
		printf("이격된 위치 삽입 불허.\n");
	else if (listcount == 0 && position == 1) {
		tmp = (node*)malloc(sizeof(node));
		tmp->data = data;
		p = tmp;
		p->next = NULL;
		listcount++;
	}
	else if (position > listcount) {
		tmp = p;
		for (int i = 1; i < position - 1; i++)
			tmp = tmp->next;
		tmp->next = (node*)malloc(sizeof(node));
		tmp->next->data = data;
		tmp->next->next = NULL;
		listcount++;
	}
	else if (position <= listcount && position > 1) {
		q = (node*)malloc(sizeof(node));
		tmp = p;
		q->data = data;
		for (int i = 1; i < position - 1; i++)
			tmp = tmp->next;
		q->next = tmp->next;
		tmp->next = q;
		listcount++;
	}
	else if (position == 1) {
		q = (node*)malloc(sizeof(node));
		q->data = data;
		tmp = p;
		q->next = tmp;
		p = q;

		listcount++;
	}

	return p;
}
nptr List::Delete(int position, nptr p) {
	nptr tmp = NULL, q = NULL;
	if (IsEmpty())
		printf("리스트가 비어있습니다.\n");
	else if (position > listcount || position < 0) {
		printf("잘못된 위치 지정.\n");
		return p;
	}
	else if (position > 1) {
		tmp = p;
		q = p;
		for (int i = 1; i < position; i++)
			tmp = tmp->next;
		for (int i = 1; i < position - 1; i++)
			q = q->next;
		q->next = tmp->next;
		free(tmp);
		listcount--;
	}
	else if (position == 1) {
		tmp = p;
		p = p->next;
		free(tmp);
		listcount--;
	}
	return p;
}
void List::List_view(nptr p) {
	nptr temp = p;
	if(IsEmpty())
		printf("리스트가 비어있습니다.\n");
	else{
	printf("리스트 : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	}
}
void List::Destroy(nptr p) {
	if (listcount == 0)
		printf("리스트가 비어있습니다.\n");
	else {
		printf("리스트 모두 초기화.\n");
		listcount = 0; listmax = 0;
		free(p);
	}

}
int List::Length() {
	printf("리스트의 길이 : %d\n", listcount);
	return listcount;
}