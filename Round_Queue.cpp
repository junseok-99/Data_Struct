#include <iostream>
using namespace std;
#define max 7
int Q[max];
int front;
int rear;
int cnt;
void Create() {
	front = 0;
	rear = -1;
	cnt = 0;
}
bool IsEmpty() {
	return (cnt==0);
}
bool IsFull() {
	return (cnt== max);
}
void Add(int data) {
	if (IsFull())
		cout << "Queue Full" << endl;
	else {
		cout << "Add data : " << data << endl;
		rear = (rear + 1) % max;
		Q[rear] = data;
		cnt++;
	}
}

void Remove() {
	if (IsEmpty())
		cout << "Queue Empty" << endl;
	else{
		cout << "Remove data : " << Q[front] << endl;
		front = (front + 1) % max;
		cnt--;
	}
}

int GetSize() {
	return cnt;
}
int GetFront() {
	return Q[front];
}

void Destroy() {
	if (IsEmpty())
		cout << "Queue Empty" << endl;
	else {
		front = 0;
		rear = -1;
		cnt = 0;
		cout << "Queue Destroy" << endl;
	}
}
void Queue_View() {
	if (IsEmpty())
		cout << "Queue Empty" << endl;
	else {
		int tmp_f = front, tmp_r = rear;
		cout << "Queue in data : ";
		while (true) {
			cout << Q[tmp_f] << " ";
			tmp_f++;
			if (tmp_f >=max )
				tmp_f = 0;
			if (tmp_f == tmp_r) {
				cout << Q[tmp_f] << " ";
				break;
			}
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
	Add(14); Add(15); Add(16); 
	Queue_View();
	Remove(); Queue_View();
	Remove(); Queue_View();
	Remove(); Queue_View();
	Add(17);
	Queue_View();
	cout << "Queue Size = " << GetSize() << endl;
	cout << "Queue Front = " << GetFront() << endl;
	Destroy();
	Queue_View();
	return 0;
}