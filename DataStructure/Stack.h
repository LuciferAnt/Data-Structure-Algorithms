#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct StackNode;
typedef struct StackNode *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack();
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType Pop(Stack S);
void DisposeStack(Stack S);
void Print(Stack S);

struct StackNode{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S){
    return S->Next == nullptr;
}

Stack CreateStack(){
    Stack S = new StackNode;
    S->Next = nullptr;
    return S;
}

void MakeEmpty(Stack S){
    if(S == nullptr){
        return;
    }else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

void Push(ElementType X, Stack S){
    PtrToNode tmpCell = new StackNode;

    tmpCell->Element = X;
    tmpCell->Next = S->Next;
    S->Next = tmpCell;
}

ElementType Top(Stack S){
    if(!IsEmpty(S)){
        return S->Next->Element;
    }
    return -1;
}

ElementType Pop(Stack S){
    if(!IsEmpty(S)){
        ElementType tmp;
        PtrToNode firstCell = S->Next;
        tmp = firstCell->Element;
        S->Next = firstCell->Next;
        delete firstCell;
        return tmp;
    }
    return -1;
}

void DisposeStack(Stack S){
    PtrToNode P = S->Next, tmp;
    S->Next = nullptr;
    while(P != nullptr){
        tmp = P->Next;
        delete P;
        P = tmp;
    }
}

void Print(Stack S){
    PtrToNode P = S->Next;
    while(P != nullptr){
        cout << P->Element << "->";
        P = P->Next;
    }
    cout << endl;
}
#endif // STACK_H
