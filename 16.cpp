#include <iostream>
#include "LIST16.h"

int main() {
    List L;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    std::cout << "\n";
    DELETE_LIST(LOCATE(1, L), L);
    PRINT_LIST(L);
    std::cout << "\n";
    DELETE_LIST(LOCATE(RETRIEVE(LOCATE(3, L), L), L), L);
    PRINT_LIST(L);
    std::cout << "\n";
}