#ifndef HashSep_H
#define HashSep_H

#include <math.h>
#include <iostream>
#include <string>

using namespace std;

namespace HashSep{
    typedef string ElementType;
    struct ListNode;
    typedef struct ListNode *Position;
    struct HashTbl;
    typedef struct HashTbl *HashTable;

    HashTable InitializeTable(int TableSize);
    void DestroyTable(HashTable H);
    int Hash(ElementType Key, int TableSize);
    Position Find(ElementType Key, HashTable H);
    void Insert(ElementType Key, HashTable H);
    void Delete(ElementType Key, HashTable H);

    struct ListNode{
        ElementType Element;
        Position Next;
    };

    typedef Position List;

    struct HashTbl{
        int TableSize;
        List *TheLists;
    };

    static int NextPrime(int x){ // 寻找下一个素数
        if(x == 1){
            return 2;
        }
        int n = x % 2 ? x + 2 : x + 1;
        while(true){
            int i = 2;
            while(n % i != 0 && i < sqrt(n)){
                ++i;
            }
            if(n % i == 0){
                n +=2;
            }else{
                break;
            }
        }
        return n;
    }


    HashTable InitializeTable(int TableSize){ // 初始化Hash表
        HashTable H;
        int i;
        H = new HashTbl;
        H->TableSize = NextPrime(TableSize);
        H->TheLists = new List[H->TableSize];
        for(i = 0; i < H->TableSize; ++i){
            H->TheLists[i] = new ListNode;
            H->TheLists[i]->Next = nullptr;
        }
        return H;
    }

    int Hash(ElementType Key, int TableSize){ // Hash函数
        unsigned int HashVal = 0;
        const char *key = Key.c_str();
        while(*key != '\0'){
            HashVal = (HashVal << 5) + (*key++); // 移位操作，相当于乘以32
        }
        return HashVal % TableSize;
    }

    Position Find(ElementType Key, HashTable H){
        Position P;
        List L;

        L = H->TheLists[Hash(Key, H->TableSize)];
        P = L->Next;
        while(P != nullptr && P->Element != Key){
            P = P->Next;
        }
        return P;
    }

    void Insert(ElementType Key, HashTable H){
        Position Pos, newCell;
        List L;

        L = H->TheLists[Hash(Key, H->TableSize)];
        Pos = L->Next;
        while(Pos != nullptr && Pos->Element != Key){
            Pos = Pos->Next;
        }
        if(Pos == nullptr){
            newCell = new ListNode;
            newCell->Element = Key;
            newCell->Next = L->Next;
            L->Next = newCell;
        }
    }

    void Delete(ElementType Key, HashTable H){
        Position Pos, tmpCell;
        List L;

        L = H->TheLists[Hash(Key, H->TableSize)];
        Pos = L;
        while(Pos->Next != nullptr && Pos->Next->Element != Key){
            Pos = Pos->Next;
        }
        if(Pos->Next != nullptr){
            tmpCell = Pos->Next;
            Pos->Next = tmpCell->Next;
            delete(tmpCell);
        }
    }

    void DestroyTable(HashTable H){ // 销毁Hash表，主要是List的销毁
        if(H == nullptr){
            return;
        }
        for(int i = 0; i < H->TableSize; ++i){
            List L = H->TheLists[i];
            Position P = L->Next;
            L->Next = nullptr;
            Position tmp;
            while(P != nullptr){
                tmp = P->Next;
                delete(P);
                P = tmp;
            }
        }
    }
}


#endif
