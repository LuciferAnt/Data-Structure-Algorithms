#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    // test List
    List L = CreateList();
    Insert(3, L, L);
    Insert(2, L, L);
    Insert(5, L, L);
    Print(L);
    Delete(2, L);
    Print(L);
    DeleteList(L);
    Print(L);
    return 0;
}
