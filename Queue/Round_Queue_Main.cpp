#include "Round_Queue_Class.h"

int main() {

	Q_Head head;
	Round_Queue round_q;

	head.Create(&round_q);
	head.Add(&round_q,10);
	head.Add(&round_q,11);
	head.Add(&round_q,12);
	head.Add(&round_q,13);
	head.Add(&round_q,14); head.Add(&round_q,15); head.Add(&round_q,16);
	head.Queue_View(&round_q);
	head.Remove(&round_q); head.Queue_View(&round_q);
	head.Remove(&round_q); head.Queue_View(&round_q);
	head.Remove(&round_q); head.Queue_View(&round_q);
	head.Add(&round_q,17);
	head.Queue_View(&round_q);
	cout << "Queue's Size = " << head.GetSize(&round_q) << endl;
	cout << "Queue's Front = " << head.GetFront(&round_q) << endl;
	head.Destroy(&round_q);
	head.Queue_View(&round_q);
	return 0;
}