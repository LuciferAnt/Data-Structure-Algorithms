#ifndef LeftHeap_H
#define LeftHeap_H


namespace LeftHeap{
    typedef int ElementType;
    struct TreeNode;
    typedef struct TreeNode *PriorityQueue;

    PriorityQueue Initialize(void);
    ElementType FindMin(PriorityQueue H);
    int IsEmpty(PriorityQueue H);
    PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
    static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
    void SwapChildren(PriorityQueue H);
    PriorityQueue Insert(ElementType X, PriorityQueue H);
    PriorityQueue DeleteMin(PriorityQueue H);

    struct TreeNode{
        ElementType Element;
        PriorityQueue Left;
        PriorityQueue Right;
        int Npl;
    };

    PriorityQueue Initialize(void){
        return nullptr;
    }

    ElementType FindMin(PriorityQueue H){
        if(IsEmpty(H)){
            return -1;
        }else{
            return H->Element;
        }
    }

    int IsEmpty(PriorityQueue H){
        return H == nullptr;
    }

    // 合并
    void SwapChildren(PriorityQueue H){
        if(H == nullptr){
            return;
        }
        PriorityQueue P = H->Left;
        H->Left = H->Right;
        H->Right = P;
    }

    static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2){
           if(H1->Left == nullptr){
               H1->Left = H2;
           }else{
               H1->Right = Merge(H1->Right, H2);
               if(H1->Left->Npl < H1->Right->Npl){
                   SwapChildren(H1);
               }
               H1->Npl = H1->Right->Npl + 1;
           }
        return H1;
    }

    PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2){
        if(H1 == nullptr){
            return H2;
        }
        if(H2 == nullptr){
            return H1;
        }
        if(H1->Element < H2->Element){
            return Merge1(H1, H2);
        }else{
            return Merge1(H2, H1);
        }
    }

    PriorityQueue Insert(ElementType X, PriorityQueue H){
        PriorityQueue SingleNode = new TreeNode;
        SingleNode->Element = X;
        SingleNode->Left = SingleNode->Right = nullptr;
        H = Merge(SingleNode, H);
    }

    PriorityQueue DeleteMin(PriorityQueue H){
        PriorityQueue leftHeap, rightHeap;
        if(IsEmpty(H)){
            return H;
        }
        leftHeap = H->Left;
        rightHeap = H->Right;
        delete H;
        return Merge(leftHeap, rightHeap);
    }


}

#endif
