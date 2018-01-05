#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <queue>
using namespace std;

namespace AvlTree{
    struct AvlNode;
    typedef int ElementType;
    typedef struct AvlNode *Position;
    typedef struct AvlNode *AvlTree;

    AvlTree CreateAvlTree();
    AvlTree MakeEmpty(AvlTree T);
    Position Find(ElementType X, AvlTree T);
    Position FindMin(AvlTree T);
    Position FindMax(AvlTree);
    AvlTree Insert(ElementType X, AvlTree T);
    AvlTree Delete(ElementType X, AvlTree T);
    void LevelTraverse(AvlTree T);
    static int Height(Position P);
    static Position SingleRotateWithLeft(Position K2);
    static Position DoubleRotateWithLeft(Position K3);
    static Position SingleRotateWithRight(Position K2);
    static Position DoubleRotateWithRight(Position K3);

    struct AvlNode{
        ElementType Element;
        AvlTree Left;
        AvlTree Right;
        int Height;
    };

    static int Max(int x, int y){
        return x > y ? x : y;
    }

    static int Height(Position P){
        if(P == nullptr){
            return -1;
        }else{
            return P->Height;
        }
    }

    AvlTree CreateAvlTree(){
        return nullptr;
    }

    AvlTree MakeEmpty(AvlTree T){
        if(T != nullptr){
            MakeEmpty(T->Left);
            MakeEmpty(T->Right);
            delete(T);
        }
        return nullptr;
    }

    Position Find(ElementType X, AvlTree T){
        if(T == nullptr){
            return nullptr;
        }
        if(X < T->Element){
            return Find(X, T->Left);
        }else if(X > T->Element){
            return Find(X, T->Right);
        }else{
            return T;
        }
    }

    Position FindMin(AvlTree T){
        if(T == nullptr){
            return nullptr;
        }
        if(T->Left == nullptr){
            return T;
        }else{
            return FindMin(T->Left);
        }
    }

    Position FindMax(AvlTree T){
        if(T == nullptr){
            return nullptr;
        }
        if(T->Right == nullptr){
            return T;
        }else{
            return FindMax(T->Right);
        }
    }

    AvlTree Insert(ElementType X, AvlTree T){
        if(T == nullptr){
            T = new AvlNode;
            T->Element = X;
            T->Left = T->Right = nullptr;
            T->Height = 0;
        }else if(X < T->Element){
            T->Left = Insert(X, T->Left);
            if(Height(T->Left) - Height(T->Right) == 2){
                if(X < T->Left->Element){
                    T = SingleRotateWithLeft(T);
                }else{
                    T = DoubleRotateWithLeft(T);
                }
            }
        }else if(X > T->Element){
            T->Right = Insert(X, T->Right);
            if(Height(T->Right) - Height(T->Left) == 2){
                if(X > T->Right->Element){
                    T = SingleRotateWithRight(T);
                }else{
                    T = DoubleRotateWithRight(T);
                }
            }
        }
        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
        return T;
    }

    AvlTree Delete(ElementType X, AvlTree T){
        Position tmpCell;
        if(T == nullptr){
            return nullptr;
        }else if(X < T->Element){
            T->Left = Delete(X, T->Left);
        }else if (X > T->Element){
            T->Right = Delete(X, T->Right);
        }else if(T->Left && T->Right){
            tmpCell = FindMin(T->Right);
            T->Element = tmpCell->Element;
            T->Right = Delete(T->Element, T->Right);
        }else{
            tmpCell = T;
            if(T->Left == nullptr){
                T = T->Right;
            }else if(T->Right == nullptr){
                T = T->Left;
            }
            delete(tmpCell);
        }
        if(T != nullptr){
            if(Height(T->Left) - Height(T->Right) == 2) {
                if (Height(T->Left->Right) - Height(T->Left->Left) == 1) {
                    T = DoubleRotateWithLeft(T);
                } else {
                    T = SingleRotateWithLeft(T);
                }
            }else if(Height(T->Right) - Height(T->Left) == 2){
                if(Height(T->Right->Left) - Height(T->Right->Right) == 1){
                    T = DoubleRotateWithRight(T);
                }else{
                    T = SingleRotateWithRight(T);
                }
            }
            T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
        }
        return T;
    }

    static Position SingleRotateWithLeft(Position K2){
        Position K1 = K2->Left;
        K2->Left = K1->Right;
        K1->Right = K2;
        K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
        K1->Height = Max(Height(K1->Left), K2->Height) + 1;
        return K1;
    }

    static Position DoubleRotateWithLeft(Position K3){
        K3->Left = SingleRotateWithRight(K3->Left);
        return SingleRotateWithLeft(K3);
    }

    static Position SingleRotateWithRight(Position K2){
        Position K1 = K2->Right;
        K2->Right = K1->Left;
        K1->Left = K2;
        K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
        K1->Height = Max(Height(K1->Right), K2->Height) + 1;
        return K1;
    }

    static Position DoubleRotateWithRight(Position K3){
        K3->Right = SingleRotateWithLeft(K3->Right);
        return SingleRotateWithRight(K3);
    }

    void LevelTraverse(AvlTree T){
        queue<AvlTree> Q;
        if(T == nullptr){
            return;
        }
        Q.push(T);
        while(!Q.empty()){
            Position P = Q.front();
            cout << P->Element << " ";
            if(P->Left != nullptr){
                Q.push(P->Left);
            }
            if(P->Right != nullptr){
                Q.push(P->Right);
            }
            Q.pop();
        }
    }



}




#endif
