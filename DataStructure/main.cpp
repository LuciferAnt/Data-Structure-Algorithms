#include <iostream>
// #include "List.h"
// #include "Stack.h"
// #include "StackArray.h"
// #include "QueueArray.h"
// #include "Queue.h"
#include "Tree.h"

using namespace std;
using namespace BinarySearchTree;

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
    /*
    Stack S = CreateStack(1);
    Push(5, S);
    Push(6, S);
    Push(1, S);
    Print(S);
    cout << Pop(S) << endl;
    Print(S);
    DisposeStack(S);
    */

    // test Queue
    /*
    Queue Q = CreateQueue();
    Enqueue(1, Q);
    Enqueue(2, Q);
    Enqueue(5, Q);
    Print(Q);
    cout << Dequeue(Q) << endl;
    Print(Q);
    Enqueue(4, Q);
    Enqueue(5, Q);
    Print(Q);
    DisposeQueue(Q);
    Print(Q);
    */

    // test Binary Search Tree

    SearchTree T = CreateTree();
    T = Insert(6, T);
    T = Insert(2, T);
    T = Insert(1, T);
    T = Insert(4, T);
    T = Insert(8, T);
    T = Insert(3, T);
    T = Insert(5, T);
    //T = Delete(5, T);
    //T = Delete(4, T);
    //cout << FindMin(T)->Element << " " << FindMax(T)->Element << endl;
    //cout << Find(2, T)->Element << endl;
    PreOrderTraverse(T);
    cout << endl;
    InOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    cout << endl;
    LevelTraverse(T);
    cout << endl;

    return 0;
}
