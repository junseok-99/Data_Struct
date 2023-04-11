#include "Tree_Class.h"

typedef node* Nptr;
Nptr head;


int main() {

    TreeClass tc;
    int arr[10] = { 6,4,8,3,5,7,9,1,2,10 };

    for (int i = 0; i < 10; i++)
        head = tc.Insert(head, arr[i]);

    tc.Delete(head, 8);
    tc.PreOrder(head);



    return 0;
}