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
    Position p = L;
    while (p->Next != NULL) {
        if (p->Next->Element > x) {
            break;
        }
        else p = p->Next;
    }
    INSERT_LIST(x, p, L);
}
void ADVANCED_ADD_LIST(ElementType x, List &L) {
    Position p = L;
    bool stop_signal = false;
    while (p->Next != NULL) {
        if (p->Next->Element == x) {
            stop_signal = true;
            break;
        }
        else if (p->Next->Element > x) {
            break;
        }
        else p = p->Next;
    }
    if (!stop_signal) INSERT_LIST(x, p, L);
}
void DEL_ELEMENT(ElementType x, List &L) {
    Position p = L;
    while (p->Next != NULL) {
        if (p->Next->Element == x) {
            DELETE_LIST(p, L);
            break;
        }
        else p = p->Next;
    }
}
void INPUT_LIST(List &L) {
    int amount;
    ElementType x;
    std::cout << "List amount: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        ADD_LIST(x, L);
    }
}
void DEL_DUP(List &L) {
    Position first = L;
    Position second = L->Next;
    while (first->Next != NULL) {
        while (second->Next != NULL) {
            if (first->Next->Element == second->Next->Element) {
                DELETE_LIST(second, L);
            }
            second = second->Next;
        }
        first = first->Next;
        second = first->Next;
    }
}
void ADVANCED_INPUT_LIST(List &L) {
    int amount;
    ElementType x;
    std::cout << "List amount: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        ADVANCED_ADD_LIST(x, L);
    }
}
int main() {
    List L;
    MAKENULL_LIST(L);
//    INPUT_LIST(L);
    ADVANCED_INPUT_LIST(L);
    PRINT_LIST(L);
    ADD_LIST(40, L);
    PRINT_LIST(L);
//    DEL_ELEMENT(40, L);
    DEL_DUP(L);
    PRINT_LIST(L);
}