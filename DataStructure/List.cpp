#include "List.h"

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
    P->Next = tmpCell
}

void DeleteList(List L){
    Position P, tmpCell;

    P = L->Next;
    while(P != nullptr){
        tmpCell = P->Next;
        delete P;
        P = tmpCell;
    }
    delete L;
}

Position Header(List L){
    return L;
}

Position First(List L){
    return L->Next;
}

void Print(List L){
    Position P = L;
    while(P->Next != nullptr){
        cout << P->Element << "->";
    }
    cout << "nullptr";
}
