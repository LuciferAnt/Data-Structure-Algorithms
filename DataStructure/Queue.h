#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

typedef int ElementType;
struct QueueNode;
typedef struct QueueNode *PtrToNode;
typedef PtrToNode Queue;
typedef PtrToNode Position;

int IsEmpty(Queue Q);
Queue CreateQueue();
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
ElementType Dequeue(Queue Q);
ElementType Front(Queue Q);
void Enqueue(ElementType X, Queue Q);
void Print(Queue Q);

struct QueueNode{
    ElementType Element;
    Position Next;
};

int IsEmpty(Queue Q){
    return Q->Next == nullptr;
}

Queue CreateQueue(){
    Queue Q = new QueueNode;
    Q->Next = nullptr;
    return Q;
}

void Enqueue(ElementType X, Queue Q){
    Position P = Q, tmpCell;
    while(P->Next != nullptr){
        P = P->Next;
    }
    tmpCell = new QueueNode;
    tmpCell->Element = X;
    tmpCell->Next = P->Next;
    P->Next = tmpCell;
}

ElementType Dequeue(Queue Q){
    if(IsEmpty(Q)){
        return -1;
    }else{
        Position P = Q->Next;
        ElementType temp;
        temp = P->Element;
        Q->Next = P->Next;
        delete P;
        return temp;
    }
}

ElementType Front(Queue Q){
    if(IsEmpty(Q)){
        return -1;
    }else{
        return Q->Next->Element;
    }
}

void DisposeQueue(Queue Q){
    Position P = Q->Next, tmpCell;
    Q->Next = nullptr;
    while(P != nullptr){
        tmpCell = P->Next;
        delete P;
        P = tmpCell;
    }
}

void Print(Queue Q){
    Position P = Q->Next;
    while(P != nullptr){
        cout << P->Element << "->";
        P = P->Next;
    }
    cout << endl;
}

#endif // QUEUE_H
