#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <iostream>

using namespace std;

namespace StackArray{
    typedef int ElementType;
    struct StackRecord;
    typedef struct StackRecord *Stack;

    int IsEmpty(Stack S);
    int IsFull(Stack S);
    Stack CreateStack(int MaxElements);
    void DisposeStack(Stack S);
    void MakeEmpty(Stack S);
    void Push(ElementType X, Stack S);
    ElementType Top(Stack S);
    ElementType Pop(Stack S);
    void Print(Stack S);

    struct StackRecord{
        int Capacity;
        int TopOfStack;
        ElementType *Array;
    };

    int IsEmpty(Stack S){
        return S->TopOfStack == -1;
    }

    int IsFull(Stack S){
        return S->TopOfStack == S->Capacity - 1;
    }

    Stack CreateStack(int MaxElements){
        Stack S = new StackRecord;

        S->Capacity = MaxElements;
        S->Array = new ElementType[MaxElements];
        MakeEmpty(S);

        return S;
    }

    void DisposeStack(Stack S){
        delete S->Array;
        delete S;
    }

    void MakeEmpty(Stack S){
        S->TopOfStack = -1;
    }

    void Push(ElementType X, Stack S){
        if(IsFull(S)){
            return;
        }else{
            S->Array[++S->TopOfStack] = X;
        }
    }

    ElementType Top(Stack S){
        if(IsEmpty(S)){
            return -1;
        }else{
            return S->Array[S->TopOfStack];
        }
    }

    ElementType Pop(Stack S){
        if(IsEmpty(S)){
            return -1;
        }else{
            return S->Array[S->TopOfStack--];
        }
    }

    void Print(Stack S){
        if(!IsEmpty(S)){
            for(int i = 0; i <= S->TopOfStack; ++i){
                cout << S->Array[i] << "->";
            }
        }
        cout << endl;
    }
}



#endif // STACKARRAY_H
