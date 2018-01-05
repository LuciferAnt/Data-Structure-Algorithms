#ifndef BinHeap_H
#define BinHeap_H

namespace BinHeap{
    const int MinData = -9999;
    typedef int ElementType;
    struct HeapStruct;
    typedef struct HeapStruct *PriorityQueue;

    PriorityQueue Initialize(int MaxElements);
    void Destroy(PriorityQueue H);
    void MakeEmpty(PriorityQueue H);
    void Insert(ElementType X, PriorityQueue H);
    ElementType DeleteMin(PriorityQueue H);
    ElementType FindMin(PriorityQueue H);
    int IsEmpty(PriorityQueue H);
    int IsFull(PriorityQueue H);

    struct HeapStruct{
        int Capacity;
        int Size;
        ElementType *Elements;
    };

    // 给定大小，初始化堆
    PriorityQueue Initialize(int MaxElements){
        PriorityQueue H;

        H = new HeapStruct;
        // 数组第一位留空，作为哑变量
        H->Elements = new ElementType[MaxElements + 1];
        H->Capacity = MaxElements;
        H->Size = 0;
        H->Elements[0] = MinData;

        return H;
    }

    // 销毁堆
    void Destroy(PriorityQueue H){
        if(H == nullptr){
            return;
        }else{
            delete H;
        }
    }

    void MakeEmpty(PriorityQueue H){
        if(H == nullptr){
            return;
        }else{
            H->Size = 0;
        }
    }

    int IsEmpty(PriorityQueue H){
        if(H == nullptr){
            return -1;
        }else{
            return H->Size == 0;
        }
    }

    int IsFull(PriorityQueue H){
        if(H == nullptr){
            return -1;
        }else{
            return H->Size == H->Capacity;
        }
    }

    void Insert(ElementType X, PriorityQueue H){
        int i;
        if(IsFull(H)){
            return;
        }
        for(i = ++H->Size; H->Elements[i / 2] > X; i /= 2){
            H->Elements[i] = H->Elements[i / 2];
        }
        H->Elements[i] = X;
    }

    ElementType DeleteMin(PriorityQueue H){
        int i, child;
        ElementType minElement, lastElement;
        if(IsEmpty(H)){
            return H->Elements[0];
        }

        minElement = H->Elements[1];
        lastElement = H->Elements[H->Size--];

        // 下滤操作
        for(i = 1; i * 2 <= H->Size; i = child){
            child = i * 2;
            // 先判断有无右节点
            if(child != H->Size && H->Elements[child + 1] < H->Elements[child]){
                child++;
            }
            if(lastElement > H->Elements[child]){
                H->Elements[i] = H->Elements[child];
            }else{
                break;
            }
        }
        H->Elements[i] = lastElement;
        return minElement;
    }

    ElementType FindMin(PriorityQueue H){
        if(IsEmpty(H)){
            return H->Elements[0];
        }else{
            return H->Elements[1];
        }
    }

}






#endif