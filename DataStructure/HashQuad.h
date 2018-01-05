#ifndef HashQuad_H
#define HashQuad_H

#include <string>
#include "math.h"

using namespace std;

namespace HashQuad{
    typedef string ElementType;
    typedef unsigned int Index;
    typedef Index Position;

    struct HashTbl;
    typedef struct HashTbl *HashTable;

    HashTable InitializeTable(int TableSize);
    void DestroyTable(HashTable H);
    Index Hash(ElementType Key, int TableSize);
    Position Find(ElementType Key, HashTable H);
    void Insert(ElementType Key, HashTable H);
    void Delete(ElementType Key, HashTable H);

    enum KindOfEntry{
        Legitimate,
        Empty,
        Deleted
    };

    struct HashEntry{
        ElementType Element;
        KindOfEntry Info;
    };

    typedef struct HashEntry Cell;

    struct HashTbl{
        int TableSize;
        Cell *TheCells;
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

    HashTable InitializeTable(int TableSize){
        HashTable H;
        int i;
        H = new HashTbl;
        H->TableSize = NextPrime(TableSize);

        H->TheCells = new HashEntry[H->TableSize];

        for(i = 0; i < H->TableSize; ++i){
            H->TheCells[i].Info = Empty; // 初始为空
        }
        return H;
    }

    Index Hash(ElementType Key, int TableSize){ // Hash函数
        unsigned int HashVal = 0;
        const char *key = Key.c_str();
        while(*key != '\0'){
            HashVal = (HashVal << 5) + (*key++); // 移位操作，相当于乘以32
        }
        return HashVal % TableSize;
    }

    Position Find(ElementType Key, HashTable H){
        Position currentPos;
        int collisionNum;

        collisionNum = 0;
        currentPos = Hash(Key, H->TableSize);

        // 十分精妙的循环，采用平方探测
        while(H->TheCells[currentPos].Info != Empty &&
                H->TheCells[currentPos].Element != Key){
            currentPos += 2 * ++collisionNum - 1;
            if(currentPos >= H->TableSize){ // 超越数组大小时将其拉回来
                currentPos -= H->TableSize;
            }
        }
        return currentPos;
    }

    void Insert(ElementType Key, HashTable H){
        Position Pos;
        Pos = Find(Key, H);
        if(H->TheCells[Pos].Info != Legitimate){
            H->TheCells[Pos].Info = Legitimate;
            H->TheCells[Pos].Element = Key;
        }
    }

    void Delete(ElementType Key, HashTable H){
        Position Pos = Find(Key, H);
        if(H->TheCells[Pos].Info == Legitimate){
            H->TheCells[Pos].Info == Deleted;
        }
    }

    void DestroyTable(HashTable H){
        if(H == nullptr){
            return;
        }
        delete(H->TheCells);
    }




}



#endif
