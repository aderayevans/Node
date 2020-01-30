#include <iostream>
#include "SPACE.h"

int main() {
    Initialize();
    List L;
    MAKENULL_LIST(L);
    INSERT_LIST('g', ENDLIST(L), L);
    INSERT_LIST('h', ENDLIST(L), L);
    INSERT_LIST('x', ENDLIST(L), L);
    INSERT_LIST('i', ENDLIST(L), L);
    PRINT_LIST(L);
}