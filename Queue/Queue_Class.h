#include <iostream>
using namespace std;
#define max 10
typedef struct {
	int front;
	int rear;
	int Q[max];
}Queue;

class Q_Head
{
public:
	void Create(Queue* qptr) {
		qptr->front = 0;
		qptr->rear = -1;
		cout << "Create Queue!" << endl;
	}
	bool IsEmpty(Queue* qptr) {
		return (qptr->front > qptr->rear);
	}
	bool IsFull(Queue* qptr) {
		return (qptr->rear - qptr->front + 1) == max;
	}
	void Add(Queue* qptr, int data) {
		if (qptr->front > 0 && qptr->rear == max - 1) {
			int tmp = qptr->rear - qptr->front + 1, count = -1;
			for (int i = 0; i < tmp; i++) {
				qptr->Q[i] = qptr->Q[qptr->front++];
				count++;
			}
			qptr->front = 0;
			qptr->rear = count;
		}
		if (IsFull(qptr))
			cout << "Queue is Full" << endl;
		else {
			qptr->Q[++qptr->rear] = data;
			cout << "Add Data : " << data << endl;
		}
	}
	void Remove(Queue* qptr) {
		if (IsEmpty(qptr))
			cout << "Queue Is Empty" << endl;
		else 
			cout << "Remove Data : " << qptr->Q[qptr->front++] << endl;
		
	}
	int GetSize(Queue* qptr) {
		return (qptr->rear - qptr->front+1);
	}
	int GetFront(Queue* qptr) {
		return (qptr->Q[qptr->front]);
	}
	void Destroy(Queue* qptr) {
		if (IsEmpty(qptr))
			cout << "Queue Is Already Empty" << endl;
		else{
		qptr->front = 0;
		qptr->rear = -1;
		cout << "Destroy In Queue" << endl;
		}
	}
	void Queue_View(Queue* qptr) {
		if (IsEmpty(qptr))
			cout << "Queue Is Empty" << endl;
		else {
			cout << "Current Data In Queue : ";
			for (int i = qptr->front; i <= qptr->rear; i++) {
				cout << qptr->Q[i] << " ";
			}
			cout << endl;
		}
	}

};

