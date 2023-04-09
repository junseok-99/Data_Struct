#include "Queue_Class.h"

int main() {

	Q_Head q_head;
	Queue queue;
	q_head.Create(&queue);
	q_head.Add(&queue, 10);
	q_head.Add(&queue, 11);
	q_head.Add(&queue, 12);
	q_head.Add(&queue, 13);
	q_head.Add(&queue, 14);
	q_head.Queue_View(&queue);
	q_head.Remove(&queue); q_head.Queue_View(&queue);
	q_head.Remove(&queue); q_head.Queue_View(&queue);
	q_head.Remove(&queue); q_head.Queue_View(&queue);
	q_head.Add(&queue, 15);
	q_head.Queue_View(&queue);
	cout << "Queue's Size = " << q_head.GetSize(&queue) << endl;
	cout << "Queue's Front = " << q_head.GetFront(&queue) << endl;
	q_head.Destroy(&queue);
	q_head.Queue_View(&queue);

	return 0;
}