#ifndef DisjSet_H
#define DisjSet_H

#define NumSets 10

namespace DisjSet{

    typedef int DisjSet[NumSets + 1];
    typedef int SetType;
    typedef int ElementType;

    void Initialize(DisjSet S);
    void SetUnion(DisjSet S, SetType Root1, SetType Root2);
    SetType Find(ElementType X, DisjSet S);

    void Initialize(DisjSet S){
        int i;
        for(i = NumSets; i > 0; --i){
            // 记录高度信息
            S[i] = -1;
        }
    }

    void SetUnion(DisjSet S, SetType Root1, SetType Root2){
        // 按大小求并
        if(S[Root2] < S[Root1]){
            S[Root2] += S[Root1];
            S[Root1] = Root2;
        }else{
            S[Root1] += S[Root2];
            S[Root2] = Root1;
        }


        // 按高度求并
        /*
        if(S[Root2] < S[Root1]){
            S[Root1] = Root2;
        }else{
            if(S[Root1] == S[Root2]){
                S[Root1]--;
            }
            S[Root2] = Root1;
        }*/
    }

    SetType Find(ElementType X, DisjSet S){
        if(S[X] <= 0){
            return X;
        }else{
            // 路径压缩
            return S[X] = Find(S[X], S);
        }
    }
}

#endif
