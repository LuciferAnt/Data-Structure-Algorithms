#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>

using namespace std;

namespace BinarySearchTree{
    struct TreeNode;
    typedef struct TreeNode *Position;
    typedef struct TreeNode *SearchTree;
    typedef int ElementType;

    SearchTree CreateTree();
    SearchTree MakeEmpty(SearchTree T);
    Position Find(ElementType X, SearchTree T);
    Position FindMin(SearchTree T);
    Position FindMax(SearchTree T);
    SearchTree Insert(ElementType X, SearchTree T);
    SearchTree Delete(ElementType X, SearchTree T);
    void PreOrderTraverse(SearchTree T);
    void InOrderTraverse(SearchTree T);
    void PostOrderTraverse(SearchTree T);
    void LevelTraverse(SearchTree T);

    struct TreeNode{
        ElementType Element;
        SearchTree Left;
        SearchTree Right;
    };

    SearchTree CreateTree(){
        return nullptr;
    }

    SearchTree MakeEmpty(SearchTree T){
        if(T != nullptr){
            MakeEmpty(T->Left);
            MakeEmpty(T->Right);
            delete T;
        }
        return nullptr;
    }

    Position Find(ElementType X, SearchTree T){
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

    Position FindMin(SearchTree T){
        if(T == nullptr){
            return nullptr;
        }else if(T->Left == nullptr){
            return T;
        }else{
            return FindMin(T->Left);
        }
    }

    Position FindMax(SearchTree T){
        if(T != nullptr){
            while(T->Right != nullptr){
                T = T->Right;
            }
        }
        return T;
    }

    SearchTree Insert(ElementType X, SearchTree T){
        if(T == nullptr){
            T = new TreeNode;
            T->Element = X;
            T->Left = T->Right = nullptr;
        }else{
            if(X < T->Element){
                T->Left = Insert(X, T->Left);
            }else if(X > T->Element){
                T->Right = Insert(X, T->Right);
            }
        }
        return T;
    }

    SearchTree Delete(ElementType X, SearchTree T){
        Position tmpCell;
        if(T == nullptr){
            return nullptr;
        }else if(X < T->Element){
            T->Left = Delete(X, T->Left);
        }else if(X > T->Element){
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
            delete tmpCell;
        }
        return T;
    }

    void PreOrderTraverse(SearchTree T){
        if(T == nullptr){
            return;
        }
        cout << T->Element << " ";
        PreOrderTraverse(T->Left);
        PreOrderTraverse(T->Right);
    }

    void InOrderTraverse(SearchTree T){
        if(T == nullptr){
            return;
        }
        InOrderTraverse(T->Left);
        cout << T->Element << " ";
        InOrderTraverse(T->Right);
    }

    void PostOrderTraverse(SearchTree T){
        if(T == nullptr){
            return;
        }
        PostOrderTraverse(T->Left);
        PostOrderTraverse(T->Right);
        cout << T->Element << " ";
    }

    void LevelTraverse(SearchTree T){
        queue<SearchTree> Q;
        if(T == nullptr){
            return;
        }else{
            Q.push(T);
            while(!Q.empty()){
                SearchTree root = Q.front();
                cout << root->Element << " ";
                if(root->Left != nullptr){
                    Q.push(root->Left);
                }
                if(root->Right != nullptr){
                    Q.push(root->Right);
                }
                Q.pop();
            }
        }
    }
}

#endif