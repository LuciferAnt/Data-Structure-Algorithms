#include <iostream>

#include "Stack.h"

using namespace std;

int main()
{
    // test List
    /*
    List L = CreateList();
    Insert(3, L, L);
    Insert(2, L, L);
    Insert(5, L, L);
    Print(L);
    Delete(2, L);
    Print(L);
    DeleteList(L);
    Print(L);
    */

    // test Stack
    Stack S = CreateStack();
    Push(5, S);
    Push(6, S);
    Push(1, S);
    Print(S);
    cout << Pop(S) << endl;
    Print(S);
    DisposeStack(S);
    Print(S);
    return 0;
}
