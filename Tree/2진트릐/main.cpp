#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX 100

typedef struct Key {
    int key;
}Key;

typedef struct node {
    Key Data;
    node* LChild;
    node* RChild;
}node;

typedef node* Nptr;
Nptr head;

Nptr CopyTree(Nptr tmp) {
    if (tmp == NULL)
        return NULL;
    else {
        Nptr tmp2 = (Nptr)malloc(sizeof(node));
        tmp2->Data.key = tmp->Data.key;
        tmp2->LChild = CopyTree(tmp->LChild);
        tmp2->RChild = CopyTree(tmp->RChild);
        return tmp2;
    }
}
Nptr Insert(Nptr tmp, int key) {
    if (tmp == NULL) {
        tmp = (Nptr)malloc(sizeof(node));
        tmp->Data.key = key;
        tmp->LChild = NULL; tmp->RChild = NULL;
    }
    else if (tmp->Data.key > key)
        tmp->LChild = Insert(tmp->LChild, key);
    else
        tmp->RChild = Insert(tmp->RChild, key);
    return tmp;
}
Nptr Search(Nptr tmp, int key) {
    if (tmp == NULL)
        cout << "No Such Node";
    else if (tmp->Data.key == key)
        return tmp;
    else if (tmp->Data.key > key)
        return Search(tmp->LChild, key);
    else
        return Search(tmp->RChild, key);
}
void PreOrder(Nptr tmp) {
    if (tmp != NULL) {
        cout << tmp->Data.key << " ";
        PreOrder(tmp->LChild);
        PreOrder(tmp->RChild);
    }
}
void SuccessorCopy(Nptr& tmp, Key& DelNodeData) {
    if (tmp->LChild == NULL) {
        DelNodeData.key = tmp->Data.key;
        Nptr tmp2 = tmp;
        tmp = tmp->RChild;
        free(tmp2);
    }
    else
        SuccessorCopy(tmp->LChild, DelNodeData);
}
void Delete(Nptr& tmp, int key) {
    if (tmp == NULL)
        cout << "No Record with Such Key";
    else if (tmp->Data.key > key)
        Delete(tmp->LChild, key);
    else if (tmp->Data.key < key)
        Delete(tmp->RChild, key);
    else if (tmp->Data.key == key) {
        if ((tmp->LChild == NULL) && (tmp->RChild == NULL)) {
            Nptr tmp2 = tmp; tmp = NULL; free(tmp2);
        }
        else if (tmp->LChild == NULL) {
            Nptr tmp2 = tmp; tmp = tmp->RChild; free(tmp2);
        }
        else if (tmp->RChild == NULL) {
            Nptr tmp2 = tmp; tmp = tmp->LChild; free(tmp2);
        }
        else
            SuccessorCopy(tmp->RChild, tmp->Data);
    }
}
int main() {

    int arr[10] = { 6,4,8,3,5,7,9,1,2,10 };

    for (int i = 0; i < 10; i++)
        head=Insert(head, arr[i]);

    Delete(head, 8);
    PreOrder(head);
        


    return 0;
}