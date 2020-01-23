#include <iostream>
#include "LIST2a.h"

void ARRANGE_LIST(List &L) {
    ElementType temp;
    Position first = L;
    Position second = L->Next;
    while (first->Next != NULL) {
        while (second->Next != NULL) {
            if (first->Next->Element > second->Next->Element) {
                temp = first->Next->Element;
                first->Next->Element = second->Next->Element;
                second->Next->Element = temp;
            }
            second = second->Next;
        }
        first = first->Next;
        second = first->Next;
    }
}
void ADD_LIST(ElementType x, List &L) {
    ARRANGE_LIST(L);
    Position p = L;
    while (p->Next != NULL) {
        if (p->Next->Element > x) {
            break;
        }
        else p = p->Next;
    }
    INSERT_LIST(x, p, L);
}
int main() {
    List L;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    ADD_LIST(40, L);
    PRINT_LIST(L);
}