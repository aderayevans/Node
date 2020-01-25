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
void MIX_LISTS(List L1, List L2, List &L3) {
    Position p1 = L1, p2 = L2, p3 = L3;
    while (p1->Next != NULL && p2->Next != NULL) {
        if (p1->Next != NULL && p2->Next == NULL) {
            INSERT_LIST(p1->Next->Element, p3, L3);
            p1 = p1->Next;
            p3 = p3->Next;
        }
        else if (p1->Next == NULL && p2->Next != NULL) {
            INSERT_LIST(p2->Next->Element, p3, L3);
            p2 = p2->Next;
            p3 = p3->Next;
        }
        else {
            if (p1->Next->Element > p2->Next->Element) {
                INSERT_LIST(p2->Next->Element, p3, L3);
                p2 = p2->Next;
                p3 = p3->Next;
            }
            else if (p1->Next->Element == p2->Next->Element) {
                INSERT_LIST(p2->Next->Element, p3, L3);
                p1 = p1->Next;
                p2 = p2->Next;
                p3 = p3->Next;
            }
            else {
                INSERT_LIST(p1->Next->Element, p3, L3);
                p1 = p1->Next;
                p3 = p3->Next;
            }
        }
    }
}
void DEL_ODDNUMBER(List &L) {
    List temp;
    MAKENULL_LIST(temp);
    Position pass = L;
    while (pass->Next != NULL) {
        if (pass->Next->Element % 2 == 0) {
            INSERT_LIST(pass->Next->Element, ENDLIST(temp), temp);
        }
        pass = pass->Next;
    }
    L = temp;
}
void SPLIT_ODD_LIST(List L, List L1, List L2) {
    Position pass = L;
    while (pass->Next != NULL) {
        if (pass->Next->Element % 2 == 0) {
            INSERT_LIST(pass->Next->Element, ENDLIST(L1), L1);
        }
        else INSERT_LIST(pass->Next->Element, ENDLIST(L2), L2);
        pass = pass->Next;
    }
}
int main() {
    List L1, L2, L3;
    MAKENULL_LIST(L1);
    MAKENULL_LIST(L2);
    MAKENULL_LIST(L3);
    ADVANCED_INPUT_LIST(L1);
    PRINT_LIST(L1);
    SPLIT_ODD_LIST(L1, L2, L3);
    PRINT_LIST(L2);
    PRINT_LIST(L3);
}