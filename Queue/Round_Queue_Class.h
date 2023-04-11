#include <iostream>
using namespace std;
#define max 10

typedef struct {
	int front;
	int rear;
	int Q[max];
}Round_Queue;

class Q_Head {
	private:
		int count;

	public:
		void Create(Round_Queue* qptr) {
			qptr->front = 0;
			qptr->rear = -1;
			count = 0;
			cout << "Create Queue!" << endl;
		}
		bool IsEmpty(Round_Queue* qptr) {
			return (count==0);
		}
		bool IsFull(Round_Queue* qptr) {
			return (count==max);
		}
		void Add(Round_Queue* qptr, int data) {
			if (IsFull(qptr))
				cout << "Queue is Full" << endl;
			else {
				qptr->rear = (qptr->rear + 1) % max ;
				qptr->Q[qptr->rear] = data;
				count++;
				cout << "Add Data : " << data << endl;
			}
		}
		void Remove(Round_Queue* qptr) {
			if (IsEmpty(qptr))
				cout << "Queue Is Empty" << endl;
			else {
				cout << "Remove Data : " << qptr->Q[qptr->front] << endl;
				qptr->front = (qptr->front + 1) % max;
				count--;
			}
		}
		int GetSize(Round_Queue* qptr) {
			return count;
		}
		int GetFront(Round_Queue* qptr) {
			return (qptr->Q[qptr->front]);
		}
		void Destroy(Round_Queue* qptr) {
			if (IsEmpty(qptr))
				cout << "Queue Is Already Empty" << endl;
			else {
				qptr->front = 0;
				qptr->rear = -1;
				count = 0;
				cout << "Destroy In Queue" << endl;
			}
		}
		void Queue_View(Round_Queue* qptr) {
			if (IsEmpty(qptr))
				cout << "Queue Is Empty" << endl;
			else {
				int tmp_f = qptr->front, tmp_r = qptr->rear;
				cout << "Current Data In Queue : ";
			while (true) {
				cout << qptr->Q[tmp_f++] << " ";
				if (tmp_f >= max)
					tmp_f = 0;
				if (tmp_f == tmp_r) {
					cout << qptr->Q[tmp_f] << " ";
					break;
				}
				}
			cout << endl;
			}
		}

};