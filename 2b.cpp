#include <iostream>
#include "LIST2b.h"

int main() {
    List L;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    std::cout << "Phan tu " << RETRIEVE(ENDLIST(L), L);
    std::cout << "\nDeleting..\n";
    DELETE_LIST(LOCATE(8, L), L);
    PRINT_LIST(L);
}