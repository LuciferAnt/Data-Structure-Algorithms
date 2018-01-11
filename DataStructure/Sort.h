#ifndef Sort_H
#define Sort_H

#include <iostream>

using namespace std;

typedef int ElementType;

// 从小到大排序

// 打印
void Print(ElementType A[], int N){
    for(int i = 0; i < N; ++i){
        cout << A[i] << " ";
    }
    cout << endl;
}

// 插入排序
void InsertionSort(ElementType A[], int N){
    int j, P;
    int tmp;
    for(P = 1; P < N; ++P){
        tmp = A[P];
        for(j = P; j > 0 && A[j - 1] > tmp; --j){
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}

// 冒泡排序
void BubbleSort(ElementType A[], int N){
    int i, j, tmp;
    for(i = 0; i < N - 1; ++i){
        for(j = 0; j < N - i - 1; ++j){
            if(A[j] > A[j + 1]){
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
}

// 选择排序
void SelectSort(ElementType A[], int N){
    int i, j, tmp;
    for(i = 0; i < N - 1; ++i){
        for(j = i + 1; j < N; ++j){
            if(A[i] > A[j]){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

// 希尔排序
void ShellSort(ElementType A[], int N){
    int i, j, increment;
    ElementType tmp;

    // shell增量
    /*
    for(increment = N / 2; increment > 0; increment /= 2){
        for(i = increment; i < N; ++i){
            tmp = A[i];
            for(j = i; j >= increment && A[j - increment] > tmp; j -= increment){
                A[j] = A[j - increment];
            }
            A[j] = tmp;
        }
    }*/

    // sedgewick增量
    int array[] = {1, 5, 19, 41, 109};
    int t;
    for(t = 0; t < 5; ++t){
        if(array[t] >= N){
            break;
        }
    }
    t -= 1;
    for(increment = array[t]; t >=0; --t, increment = array[t]){
        for(i = increment; i < N; ++i){
            tmp = A[i];
            for(j = i; j >= increment && A[j - increment] > tmp; j -= increment){
                A[j] = A[j - increment];
            }
            A[j] = tmp;
        }
    }

}

// 堆排序
void PercDown(ElementType A[], int i, int N){
    int child;
    ElementType tmp;

    for(tmp = A[i]; 2 * i + 1 < N; i = child){
        child = 2 * i + 1;
        if(child != N - 1 && A[child] < A[child + 1]){
            ++child;
        }
        if(tmp < A[child]){
            A[i] = A[child];
        }else{
            break;
        }
    }
    A[i] = tmp;
}

// Floyd
void PercolateDown(ElementType A[], int i, int N){
    int child;
    ElementType tmp;

    for(tmp = A[i]; 2 * i + 1 < N; i = child){
        child = 2 * i + 1;
        /*
        if(child != N - 1 && A[child] < A[child + 1]){
            ++child;
        }*/
        A[i] = A[child];
    }
    for(i = child; A[i / 2] < tmp; i /= 2){
        A[i] = A[i / 2];
    }
    A[i] = tmp;
}

void Swap(ElementType &a, ElementType &b){
    ElementType tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void HeapSort(ElementType A[], int N){
    int i;
    // build heap
    for(i = N / 2; i >= 0; --i){
        PercolateDown(A, i, N);
    }
    // delete max
    for(i = N - 1; i > 0; --i){
        Swap(A[0], A[i]);
        PercolateDown(A, 0, i);
    }
}


// 归并排序

void MSort(ElementType A[], ElementType tmpArray[], int Left, int Right);
void Merge(ElementType A[], ElementType tmpArray[], int Lpos, int Rpos, int RightEnd);
void MergeSort(ElementType A[], int N);

void MSort(ElementType A[], ElementType tmpArray[], int Left, int Right){
    int Center;

    if(Left < Right){
        Center = (Left + Right) / 2;
        MSort(A, tmpArray, Left, Center);
        MSort(A, tmpArray, Center + 1, Right);
        Merge(A, tmpArray, Left, Center + 1, Right);
    }
}

void MergeSort(ElementType A[] , int N){
    ElementType *tmpArray;
    tmpArray = new ElementType[N];

    MSort(A, tmpArray, 0, N - 1);
    delete(tmpArray);
}

void Merge(ElementType A[], ElementType tmpArray[], int Lpos, int Rpos, int RightEnd){
    int i, LeftEnd, NumElements, tmpPos;

    LeftEnd = Rpos - 1;
    tmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    while(Lpos <= LeftEnd && Rpos <= RightEnd){
        if(A[Lpos] <= A[Rpos]){
            tmpArray[tmpPos++] = A[Lpos++];
        }else{
            tmpArray[tmpPos++] = A[Rpos++];
        }
    }
    while(Lpos <= LeftEnd){
        tmpArray[tmpPos++] = A[Lpos++];
    }
    while(Rpos <= RightEnd){
        tmpArray[tmpPos++] = A[Rpos++];
    }
    for(i = 0; i < NumElements; ++i, RightEnd--){
        A[RightEnd] = tmpArray[RightEnd];
    }
}


// 快速排序
ElementType Median3(ElementType A[], int Left, int Right){
    int Center = (Left + Right) / 2;

    if(A[Left] > A[Center]){
        Swap(A[Left], A[Center]);
    }
    if(A[Left] > A[Right]){
        Swap(A[Left], A[Right]);
    }
    if(A[Center] > A[Right]){
        Swap(A[Center], A[Right]);
    }

    Swap(A[Center], A[Right - 1]);
    return A[Right - 1];
}

const int Cutoff = 3;

void QSort(ElementType A[], int Left, int Right){
    int i, j;
    ElementType Pivot;

    if(Left + Cutoff <= Right) {
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;
        for (;;) {
            while (A[++i] < Pivot) {}
            while (A[--j] > Pivot) {}
            if (i < j) {
                Swap(A[i], A[j]);
            } else {
                break;
            }
        }
        Swap(A[i], A[Right - 1]);

        QSort(A, Left, i - 1);
        QSort(A, i + 1, Right);
    }else{
        InsertionSort(A + Left, Right - Left + 1);
    }
}

void QuickSort(ElementType A[], int N){
    QSort(A, 0, N - 1);
}

// 快速选择
void QSelect(ElementType A[], int k, int Left, int Right){
    int i, j;
    ElementType Pivot;

    if(Left + Cutoff <= Right){
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;
        for(;;){
            while(A[++i] < Pivot){}
            while(A[--j] > Pivot){}
            if(i < j){
                Swap(A[i], A[j]);
            }else{
                break;
            }
        }
        Swap(A[i], A[Right - 1]);

        if(k <= i){
            QSelect(A, k, Left, i - 1);
        }else{
            QSelect(A, k, i + 1, Right);
        }
    }else{
        InsertionSort(A + Left, Right - Left + 1);
    }
}



#endif
