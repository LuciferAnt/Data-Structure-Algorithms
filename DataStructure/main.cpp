#include <iostream>
// #include "List.h"
// #include "Stack.h"
// #include "StackArray.h"
// #include "QueueArray.h"
// #include "Queue.h"
// #include "Tree.h"
// #include "AVLTree.h"
// #include "HashSep.h"
// #include "HashQuad.h"
// #include "BinHeap.h"
// #include "LeftHeap.h"
#include "Sort.h"

using namespace std;
//using namespace BinarySearchTree;
//using namespace AvlTree;

//using namespace HashSep;
//using namespace HashQuad;
//using namespace BinHeap;
// using namespace LeftHeap;

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
    /*
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
    */

    // test AVL Tree
    /*
    AvlTree::AvlTree T = CreateAvlTree();
    T = Insert(6, T);
    T = Insert(2, T);
    T = Insert(1, T);
    T = Insert(4, T);
    T = Insert(3, T);
    T = Insert(5, T);
    T = Delete(5, T);
    T = Delete(6, T);
    //T = Delete(5, T);
    LevelTraverse(T);*/
    /*
    cout << Find(6, T) << endl;
    cout << FindMax(T)->Element << endl;
    cout << FindMin(T)->Element << endl;
    LevelTraverse(T);*/

    // Test HashTable
    /*
    HashTable H = InitializeTable(10);
    cout << H->TableSize << endl;
    Insert("abc", H);
    Insert("def", H);
    Insert("ghi", H);
    cout << Find("abc", H) << endl;
    cout << Find("jk", H) << endl;
    Delete("abc", H);
    cout << Find("abc", H) << endl;
    */

    // Test PriorityQueue
    /*
    PriorityQueue H = Initialize(10);
    Insert(2, H);
    Insert(5, H);
    Insert(8, H);
    Insert(4, H);
    cout << FindMin(H) << endl;
    DeleteMin(H);
    cout << FindMin(H) << endl;
    Destroy(H);
    */

    // Test LeftHeap
    /*
    PriorityQueue H = Initialize();
    H = Insert(3, H);
    H = Insert(10, H);
    H = Insert(14, H);
    H = Insert(8, H);
    H = Insert(23, H);
    H = DeleteMin(H);
    cout << FindMin(H) << endl;
    */

    // Test sort
    int A[] = {34, 8, 64, 51, 32, 21};
    HeapSort(A, 6);
    Print(A, 6);





    return 0;
}
