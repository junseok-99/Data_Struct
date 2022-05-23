#include <iostream>
using namespace std;
#define max 5
int Q[max];
int front;
int rear;

void Create() {
	front = 0;
	rear = -1;
}
bool IsEmpty() {
	return (front>rear);
}
bool IsFull() {
	return (rear-front+1)==max;
}
void Add(int data) {
	if (front != 0 && rear == max - 1) {
		int tmp = rear - front + 1;
		int count = -1;
		for (int i = 0; i < tmp; i++) {
			Q[i] = Q[front++];
			count++;
		}
		front = 0;
		rear = count;
	}
	if (IsFull())
		cout << "Queue Full" << endl;
	else {
		Q[++rear] = data;
		cout << "Add data : " << data << endl;
	}
}

void Remove() {
	if (IsEmpty())
		cout << "Queue Empty" << endl;
	else
	cout<<"Remove data : "<<Q[front++]<<endl;
	
}

int GetSize() {
	return (rear - front+1);
}
int GetFront() {
	return Q[front];
}

void Destroy() {
	if(IsEmpty())
		cout << "Queue Empty" << endl;
	else {
		front = 0;
		rear = -1;
		cout << "Queue Destroy" << endl;
	}
}
void Queue_View() {
	if (IsEmpty())
		cout << "Queue Empty" << endl;
	else{
	cout << "Queue in data : ";
	for (int i = front; i <= rear; i++) {
		cout << Q[i]<<" ";
	}
	cout << endl;
	}
}
int main() {
	Create();
	Add(10);
	Add(11);
	Add(12);
	Add(13);
	Add(14);
	Queue_View();
	Remove(); Queue_View();
	Remove(); Queue_View();
	Remove(); Queue_View();
	Add(15);
	Queue_View();
	cout << "Queue Size = " << GetSize() << endl;
	cout << "Queue Front = " << GetFront() << endl;
	Destroy();
	Queue_View();
	return 0;
}