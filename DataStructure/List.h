#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
void Print(List L);

struct Node{
    ElementType Element;
    Position Next;
};

List CreateList(){
    Position P = new Node;
    P->Next = nullptr;
    return P;
}

int IsEmpty(List L){
    return L->Next == nullptr;
}

int IsLast(Position P, List L){
    return P->Next == nullptr;
}

Position Find(ElementType X, List L){
    Position P = L->Next;
    while(P != nullptr && P->Element != X){
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L){
    Position P = L->Next, tmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P, L)){
        tmpCell = P->Next;
        P->Next = tmpCell->Next;
        delete tmpCell;
    }
}

Position FindPrevious(ElementType X, List L){
    Position P = L;
    while(P->Next != nullptr && P->Next->Element != X){
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P){
    Position tmpCell = new Node;
    tmpCell->Element = X;
    tmpCell->Next = P->Next;
    P->Next = tmpCell;
}

void DeleteList(List L){
    Position P, tmpCell;

    P = L->Next;
    L->Next = nullptr;
    while(P != nullptr){
        tmpCell = P->Next;
        delete P;
        P = tmpCell;
    }
}

Position Header(List L){
    return L;
}

Position First(List L){
    return L->Next;
}

void Print(List L){
    Position P = L->Next;
    while(P != nullptr){
        cout << P->Element << "->";
        P = P->Next;
    }
    cout << "nullptr" << endl;;
}

#endif // LIST_H
