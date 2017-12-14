#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>

using namespace std;

namespace QueueArray{
    typedef int ElementType;
    struct QueueRecord;
    typedef struct QueueRecord *Queue;

    int IsEmpty(Queue Q);
    int IsFull(Queue Q);
    Queue CreateQueue(int MaxElements);
    void DisposeQueue(Queue Q);
    void MakeEmpty(Queue Q);
    ElementType Dequeue(Queue Q);
    ElementType Front(Queue Q);
    void Enqueue(ElementType X, Queue Q);
    static int Succ(int Value, Queue Q);
    void Print(Queue Q);

    struct QueueRecord{
        int Capacity;
        int Front;
        int Rear;
        int Size;
        ElementType *Array;
    };

    int IsEmpty(Queue Q){
        return Q->Size == 0;
    }

    int IsFull(Queue Q){
        return Q->Size == Q->Capacity;
    }

    Queue CreateQueue(int MaxElements){
        Queue Q = new QueueRecord;

        Q->Capacity = MaxElements;
        Q->Array = new ElementType[MaxElements];
        MakeEmpty(Q);

        return Q;
    }

    void MakeEmpty(Queue Q){
        Q->Size = 0;
        Q->Front = 0;
        Q->Rear = -1;
    }

    static int Succ(int Value, Queue Q){
        if(++Value == Q->Capacity){
            Value = 0;
        }
        return Value;
    }

    void Enqueue(ElementType X, Queue Q){
        if(IsFull(Q)){
            return;
        }else{
            Q->Rear = Succ(Q->Rear, Q);
            Q->Array[Q->Rear] = X;
            ++Q->Size;
        }
    }

    ElementType Dequeue(Queue Q){
        ElementType temp;

        if(IsEmpty(Q)){
            return -1;
        }else{
            temp = Q->Array[Q->Front];
            Q->Front = Succ(Q->Front, Q);
            --Q->Size;
        }
        return temp;
    }

    ElementType Front(Queue Q){
        if(IsEmpty(Q)){
            return -1;
        }else{
            return Q->Array[Q->Front];
        }
    }

    void DisposeQueue(Queue Q){
        delete Q->Array;
        delete Q;
    }

    void Print(Queue Q){
        int i, j = Q->Front;
        for(i = 0; i < Q->Size; ++i){
            cout << Q->Array[j] << "->";
            j = Succ(j, Q);
        }
        cout << endl;
    }

}

#endif // QUEUEARRAY_H
