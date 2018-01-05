#ifndef BinQueue_H
#define BinQueue_H


namespace BinQueue{
    const int MaxTrees = 10;
    const int Capacity = 20;
    typedef int ElementType;
    typedef struct BinNode *Position;
    typedef Position BinTree;
    typedef struct Collection *BinQueue;

    struct BinNode{
        ElementType Element;
        Position LeftChild;
        Position NextSibling;
    };

    struct Collection{
        int CurrentSize;
        BinTree TheTrees[MaxTrees];
    };

    BinQueue Initialize(){
        BinQueue H = new Collection;
        H->CurrentSize = 0;
        H->TheTrees[MaxTrees] = new BinNode[MaxTrees];
        return H;
    }

    int IsEmpty(BinQueue H){
        return H->CurrentSize == 0;
    }

    BinTree CombineTrees(BinTree T1, BinTree T2){
        if(T1->Element > T2->Element){
            return CombineTrees(T2, T1);
        }
        T2->NextSibling = T1->LeftChild;
        T1->LeftChild = T2;
        return T1;
    }

    BinQueue Merge(BinQueue H1, BinQueue H2){
        BinTree T1, T2, Carry = nullptr;
        int i, j;

        if(H1->CurrentSize + H2->CurrentSize > Capacity){
            return nullptr;
        }

        H1->CurrentSize += H2->CurrentSize;
        for(i = 0, j = 1; j <= H1->CurrentSize; ++i, j *= 2){
            T1 = H1->TheTrees[i];
            T2 = H2->TheTrees[i];
            switch (!!T1 + 2 * !!T2 + 4 * !!Carry){
                case 0:
                case 1:
                    break;
                case 2:
                    H1->TheTrees[i] = T2;
                    H2->TheTrees[i] = nullptr;
                    break;
                case 4:
                    H1->TheTrees[i] = Carry;
                    Carry = nullptr;
                    break;
                case 3:
                    Carry = CombineTrees(T1, T2);
                    H1->TheTrees[i] = H2->TheTrees[i] = nullptr;
                    break;
                case 5:
                    Carry = CombineTrees(T1, Carry);
                    H1->TheTrees[i] = nullptr;
                    break;
                case 6:
                    Carry = CombineTrees(T2, Carry);
                    H2->TheTrees[i] = nullptr;
                    break;
                case 7:
                    H1->TheTrees[i] = Carry;
                    Carry = CombineTrees(T1, T2);
                    H2->TheTrees[i] = nullptr;
                    break;
            }
        }
        return H1;
    }

    ElementType DeleteMin(BinQueue H){
        int i, j;
        int minTree;
        BinQueue deletedQueue;
        Position deletedTree, oldRoot;
        ElementType minItem;

        if(IsEmpty(H)){
            return -1;
        }
        minItem = 9999;
        for(i = 0; i < MaxTrees; ++i){
            if(H->TheTrees[i] && H->TheTrees[i]->Element < minItem){
                minItem = H->TheTrees[i]->Element;
                minTree = i;
            }
        }
        deletedTree = H->TheTrees[minTree];
        oldRoot = deletedTree;
        deletedTree = deletedTree->LeftChild;
        delete oldRoot;

        deletedQueue = Initialize();
        deletedQueue->CurrentSize = (1 << minTree) - 1;
        for(j = minTree - 1; j >= 0; --j){
            deletedQueue->TheTrees[j] = deletedTree;
            deletedTree = deletedTree->NextSibling;
            deletedQueue->TheTrees[j]->NextSibling = nullptr;
        }
        H->TheTrees[minTree] = nullptr;
        H->CurrentSize -= deletedQueue->CurrentSize + 1;

        Merge(H, deletedQueue);
        return minItem;
    }
}

#endif
