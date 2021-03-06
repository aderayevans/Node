#include <iostream>
#include <string>
#include "LIST15.h"

using std::cout;
using std::endl;

List ADD_BIGNumber(List L1, List L2) {
    List L;
    int remember = 0;
    MAKENULL_LIST(L);
    while (true) {
        if (L1->Next == NULL && L2->Next == NULL && remember == 0) {
            break;
        }
        else if (L1->Next == NULL && L2->Next == NULL && remember != 0) {
            INSERT_LIST(remember, FIRST(L), L);
            remember = 0;
        }
        else if (L1->Next != NULL && L2->Next == NULL) {
            INSERT_LIST((L1->Next->Element + remember)%10, FIRST(L), L);
            remember = (L1->Next->Element + remember)/10;
            L1 = L1->Next;
        }
        else if (L1->Next == NULL && L2->Next != NULL) {
            INSERT_LIST((L2->Next->Element + remember)%10, FIRST(L), L);
            remember = (L2->Next->Element + remember)/10;
            L2 = L2->Next;
        }
        else {
            INSERT_LIST((L1->Next->Element + L2->Next->Element + remember)%10, FIRST(L), L);
            remember = (L1->Next->Element + L2->Next->Element + remember)/10;
            L1 = L1->Next;
            L2 = L2->Next;
        }
    }
    return L;
}
int main() {
    List L1, L2, L3;
    MAKENULL_LIST(L1);
    MAKENULL_LIST(L2);
    READ_LIST(L1);
    READ_LIST(L2);
    L3 = ADD_BIGNumber(L1, L2);
    PRINT_LIST(L3);
}