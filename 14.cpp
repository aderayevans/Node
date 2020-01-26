#include <iostream>
#include "LIST14.h"

void DERIVATIVE(List &L) {
    Position p = L;
    Position temp;
    temp->Next = NULL;
    while(p->Next != NULL) {
        if (p->Next->Element.power == 0)
            temp = p;
        else {
            p->Next->Element.number = p->Next->Element.number*p->Next->Element.power;
            p->Next->Element.power--;
        }
        p = p->Next;
    }
    DELETE_LIST(temp, L);
}
void SWAP(ElementType &x, ElementType &y) {
    ElementType temp = x;
    x = y;
    y = temp;
}
void ARRANGE(List &L) {
    Position first = L;
    Position second = L->Next;
    while (first->Next != NULL && second->Next != NULL) {
        while (second->Next != NULL) {
            if (first->Next->Element.power < second->Next->Element.power) {
                SWAP(first->Next->Element, second->Next->Element);
                second = second->Next;
            }
            else if (first->Next->Element.power > second->Next->Element.power) {
                second = second->Next;
            }
            else if (first->Next->Element.power == second->Next->Element.power) {
                first->Next->Element.number += second->Next->Element.number;
                DELETE_LIST(second, L);
            }
        }
        first = first->Next;
        second = first->Next;
    }
}
List ADD_POLIS(List L1, List L2) { //ADDITION_POLINOMIALS
    List L;
    MAKENULL_LIST(L);
    ElementType x;
    while(L1->Next != NULL && L2->Next != NULL) {
        if (L1->Next != NULL && L2->Next == NULL) {
            INSERT_LIST(L1->Next->Element, ENDLIST(L), L);
            L1 = L1->Next;
        }
        else if (L1->Next == NULL && L2->Next != NULL) {
            INSERT_LIST(L2->Next->Element, ENDLIST(L), L);
            L2 = L2->Next;
        }
        else if (L1->Next->Element.power == L2->Next->Element.power) {
            x.number = L1->Next->Element.number + L2->Next->Element.number;
            x.power = L1->Next->Element.power;
            INSERT_LIST(x, ENDLIST(L), L);
            L1 = L1->Next;
            L2 = L2->Next;
        }
        else if (L1->Next->Element.power > L2->Next->Element.power) {
            INSERT_LIST(L1->Next->Element, ENDLIST(L), L);
            L1 = L1->Next;
        }
        else {
            INSERT_LIST(L2->Next->Element, ENDLIST(L), L);
            L2 = L2->Next;
        }
    }
    return L;
}
List MULTI_POLIS(List L1, List L2) { //MULTIPLICATION_POLINOMIALS
    List L;
    Position p = L2;
    MAKENULL_LIST(L);
    ElementType x;
    while (L1->Next != NULL && L2->Next != NULL) {
        while (L2->Next != NULL) {
            x.number = L1->Next->Element.number * L2->Next->Element.number;
            x.power = L1->Next->Element.power + L2->Next->Element.power;
            INSERT_LIST(x, ENDLIST(L), L);
            L2 = L2->Next;
        }
        L1 = L1->Next;
        L2 = p;
    }
    ARRANGE(L);
    return L;
}
int main() {
    List L1, L2;
    MAKENULL_LIST(L1);
    MAKENULL_LIST(L2);
    READ_LIST(L1);
    READ_LIST(L2);
    ARRANGE(L1);
    ARRANGE(L2);
    PRINT_LIST(L1);
    List L3 = MULTI_POLIS(L1, L2);
    PRINT_LIST(L3);
}