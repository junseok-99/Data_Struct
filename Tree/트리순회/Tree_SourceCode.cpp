#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX 100

//트리
typedef struct node{
    char Name[100];
    node* LChild;
    node* RChild;
} node;

typedef node* Nptr;
Nptr t, p;

//스택
class Stack {
public:
    int top = -1;
    Nptr s_Item[MAX];
    void Create() { top = -1; }
    bool IsEmpty() { return (top == -1); }
    bool IsFULL() { return (top == MAX - 1); }
    void Push(Nptr item) { s_Item[++top] = item; }
    Nptr Pop() { return s_Item[top--]; }
};

Stack S;

//InterativePreorder
void Visit_s(Nptr tmp) {
    cout << tmp->Name << " ";
}
void IterativePreorder(Nptr tmp) {
    S.Create();
    if (tmp != NULL) {
        S.Push(tmp);
        while (!S.IsEmpty())
        {
            tmp = S.Pop();
           Visit_s(tmp);
           if (tmp->RChild != NULL)
               S.Push(tmp->RChild);
           if (tmp->LChild != NULL)
               S.Push(tmp->LChild);
        }
    }
}
// ----------------↑스택 , ↓트리 ----------------
void Visit(char t[]) {
    cout << t << " ";
}
//전위순회
void PreOrder(Nptr tmp) {
    if (tmp != NULL) {
        Visit(tmp->Name);
        PreOrder(tmp->LChild);
        PreOrder(tmp->RChild);
    }
}
//중위 순회
void InOrder(Nptr tmp) {
    if (tmp != NULL) {
        InOrder(tmp->LChild);
        Visit(tmp->Name);
        InOrder(tmp->RChild);
    }
}
//후위 순회
void PostOrder(Nptr tmp) {
    if (tmp != NULL) {
        PostOrder(tmp->LChild);
        PostOrder(tmp->RChild);
        Visit(tmp->Name);
    }
}

//큐
class Queue {
public:
    int front = 0, rear = -1;
    Nptr q_Item[MAX];
    void Create() { front = 0, rear = -1; }
    bool IsEmpty() { return (front > rear); }
    bool IsFULL() { return (rear - front + 1) == MAX; }
    void Add(Nptr item) { q_Item[++rear] = item; }
    Nptr Getfront() { return q_Item[front++]; }
};

//LevelOrder
Queue Q;
void LevelOrder(Nptr tmp) {
    Q.Create();
    Q.Add(tmp);
    while (!Q.IsEmpty()) {
        Nptr Current = Q.Getfront();
        Visit(Current->Name);
        if (Current->LChild != NULL)
            Q.Add(Current->LChild);
        if (Current->RChild != NULL)
            Q.Add(Current->RChild);
    }
}
int main() {
   
    p = (Nptr)malloc(sizeof(node));

    strcpy_s(p->Name, "Park");
    p->LChild = (Nptr)malloc(sizeof(node));
    p->RChild = (Nptr)malloc(sizeof(node));
    
    t = p->LChild;
    strcpy_s(t->Name, "Kim");
    t->LChild = (Nptr)malloc(sizeof(node));
    t->RChild = (Nptr)malloc(sizeof(node));
   
    t = p->RChild;
    strcpy_s(t->Name, "Seo");
    t->LChild = NULL;
    t->RChild = (Nptr)malloc(sizeof(node));

    t = p->LChild->LChild;
    strcpy_s(t->Name, "Ko");
    t->LChild = NULL;
    t->RChild = NULL;

    t = p->LChild->RChild;
    strcpy_s(t->Name, "Lee");
    t->LChild = NULL;
    t->RChild = NULL;
   
    t = p->RChild->RChild;
    strcpy_s(t->Name, "Cho");
    t->LChild = NULL;
    t->RChild = NULL;

    PreOrder(p);
    cout << endl;

    InOrder(p);
    cout << endl;

    PostOrder(p);
    cout << endl;
   
    IterativePreorder(p);
    cout << endl;

    LevelOrder(p);
    cout << endl;

    return 0;
}